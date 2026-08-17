# WINNER / COST 筹码分布函数 — 反编译总结

> 目标: 弘历(预测大师) `CompMan.dll` 中 WINNER / COST 成本分布函数的完整反编译
> 工具: Ghidra 12.1.2 + JDK17 (pyghidra) | 平台: Windows
> 日期: 2026-08-17 / 18

---

## 一、目标与结论

**WINNER(P)** 和 **COST(frac)** 是弘历/通达信体系的筹码分布标准函数。本次从 `CompMan.dll` 真实反编译出两个核心函数（836 + 1043 行），并**逐层验证了运行结构**：

1. **WINNER 核心 = `FUN_100ccf00`**（836 行）— 本地从 OHLCV 构建成本分布 + 查表
2. **COST 核心 = `FUN_100cf400`**（1043 行）— WINNER 的逆运算（累计占比→价位）
3. **筹码分布是本地运算**：`FUN_100ccf00` 从 `FUN_100dd8dc()`（本地 OHLCV 数据）逐根算出 `local_208`，`skbjTemp.dat` 是**本地缓存文件**（存锚点/增量），**不是服务端下发**
4. **两个函数同构**：数据加载 + 数学累加 + 线程锁 + 结果格式化。不是"一个做基建一个做数学"

---

## 二、WINNER 反编译链路（真实代码铁证）

| 层 | 函数 | 角色 |
|---|---|---|
| 派发器 | `FUN_10097610` | `operator_new(0x24)` + `FUN_100064c0("WINNER")` + `FUN_100934f0(0x138)` |
| 构造器 | `FUN_100934f0` | 按 0x138 设 14 档标志位，vtable = `PTR_WINNER_IMPL_1015e7f8` |
| **算法核心** | **`FUN_100ccf00`** | **836 行：本地从 pdVar4 构建 local_208（每根收盘价）+ WINNER 查表** |

**`aiStack_1dc[113]` 真实常量**：从反编译原文逐条提取（索引 0~112 全覆盖），落盘 `aiStack_1dc_real.txt`。
- `[0..12]` = **平年月度累计天数表**（已验证吻合）→ 日期→天数序号哈希
- `[13..]` = **月周期日历对齐表**（决定非交易日是否写入 local_208），仅 WINNER 使用

---

## 三、COST 反编译

- **`FUN_100cf400`**（1043 行）：基于成本分布，遍历找"累计占比 >= frac"的价位
- 数学本质 = `WINNER` 的逆：`COST(frac) = 使 WINNER(P) >= frac 的最小 P`
- 含 `SQRT` + `%.3lf` 格式化 + `LOCK/UNLOCK`
- **COST 完全不使用 `aiStack_1dc`**（价格轴处理，无需日期换算）→ 印证 `[13..]` 非价格桶表

---

## 四、筹码分布是谁算的（关键溯源 — 已修正）

早期分析曾误判"服务端算、本地只读"，**已被推翻**。修正后结论：

- `skbjTemp.dat` 在 `FUN_100ccf00` 中**既读（line 290, `0x8000`）也写（line 400, `0x9001`=modeRead|modeCreate）**——dll **自己读写**该缓存
- `FUN_100ccf00` **line 205-265 在打开任何文件之前**，已从 `FUN_100dd8dc()`（本地 OHLCV）逐根算出 `local_208`（成本分布核心）
- `skbjTemp.dat` 是**本地缓存文件**（锚点 + 增量，避免每次重算全历史），**不是服务端下发**

**结论：筹码分布 = 本地运算**。WINNER/COST 从本地 OHLCV 重建成本分布，与标准 TV `WINNER` 本质一致（差异仅：dll 用每根K线等权，TV 用成交量加权）。

详细修正记录见 `docs/LOCAL_COMPUTE_CORRECTION.md`、`docs/SKBJ_TRACING.md`（原始追踪，已标注被推翻）。

---

## 五、交付物清单

### 真实反编译铁证（`decompiled/`）
- `costcore_100ccf00.c` — WINNER 核心 836 行完整反编译
- `costcore_100cf400.c` — COST 核心 1043 行完整反编译
- `aiStack_1dc_real.txt` — `aiStack_1dc[113]` 113 个真实常量（原样 dump）
- `dd8dc.c` — `FUN_100dd8dc`（浮点取整辅助函数，非数据源）
- `FUN_1009e2d0.c` — 数据对象访问器
- `fn_100934f0.c` — WINNER 构造器

### 纯 WINNER/COST 实现（`src/`，两个版本）
- `winner_113.py` — WINNER(P)：等权（对齐 dll）+ 成交量加权（对齐 TV）
- `cost_113.py` — COST(frac)：等权 + 加权，WINNER↔COST 互逆验证
- `winner_113.pine` — `//@version=5`：WINNER(P) + COST(50%)，权重切换
- `cost_113.pine` — COST(frac) 独立版，权重切换

### 分析笔记（`docs/`）
- `LOCAL_COMPUTE_CORRECTION.md` — 本地运算结论（推翻"服务端算"）
- `HASH_MAPPING_SOLVED.md` — aiStack_1dc[0..12] 日期哈希破解
- `PDVAR4_FIELDS.md` — 汇编级确认 pdVar4 字段（收盘价/日期）
- `AISTACK_13PLUS.md` — [13..] 月周期对齐表分析
- `SKBJ_TRACING.md` — 上游写入模块追踪（原始，已标注推翻）
- `WINNER_完整反编译记录.md` / `WINNER_算法白皮书.md`

---

## 六、已验证

- 等权：`WINNER(C)=1.0`（收盘为最高价时 100% 获利）、`COST(0.5)=11.3 → WINNER回查=0.5`（逆运算精确）
- 加权：`ZSHTL+ZZLKP` 结构守恒（实现中已去除衍生指标，仅留纯 WINNER/COST）
- `aiStack_1dc[0..12]` 月度天数表与平年计算吻合验证

---

## 七、诚实标注的未解项

1. **`aiStack_1dc[13..]` 精确位运算语义**：推断为月周期日历对齐表（仅 WINNER 用、COST 不用、值非单调含重复、0x1d=29 月周期特征），但逐位运算未完全坐实；对连续交易日数据影响极小
2. **dll 等权 vs TV 加权**：唯一结构性差异。加权版用分位近似，若需与 TV 精确一致可拿真实渲染值做 MAE 校准
