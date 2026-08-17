# WINNER / COST 筹码分布函数 — 反编译总结

> 目标: 弘历(预测大师) `CompMan.dll` 中 WINNER / COST 成本分布函数的完整反编译
> 工具: Ghidra 12.1.2 + JDK17 (pyghidra) | 平台: Windows
> 日期: 2026-08-17 / 18

---

## 一、目标与结论

**WINNER(P)** 和 **COST(frac)** 是弘历/通达信体系的筹码分布标准函数。本次从 `CompMan.dll` 真实反编译出两个核心函数，确认：

1. **WINNER 核心 = `FUN_100ccf00`**（836 行反编译）— 成本分布累加 + 查表
2. **COST 核心 = `FUN_100cf400`**（1043 行反编译）— WINNER 的逆运算（累计占比→价位）
3. **两个函数都只读 `skbjTemp.dat`**（筹码分布缓存，由弘历数据引擎上游预计算写盘），本身不参与筹码分布的原始计算
4. **两个函数同构**：都含 数据加载(`FUN_100dd8dc`/`FUN_1009e2d0`) + 数学计算(双层循环累加) + 线程锁(`LOCK/UNLOCK`) + 结果格式化(`%.3lf`)。不是"一个做基建一个做数学"的分工

---

## 二、WINNER 反编译链路（真实代码铁证）

| 层 | 函数 | 角色 |
|---|---|---|
| 派发器 | `FUN_10097610` | line 967: `operator_new(0x24)` + `FUN_100064c0("WINNER")` + `FUN_100934f0(0x138)` |
| 构造器 | `FUN_100934f0` | 按 0x138 设 14 档标志位，vtable = `PTR_WINNER_IMPL_1015e7f8` |
| vtable | `PTR_WINNER_IMPL_1015e7f8` | 19 个虚方法（框架层） |
| **算法核心** | **`FUN_100ccf00`** | **836 行：读 skbjTemp.dat + 双层循环累加 local_208 + WINNER 查表(line 405-431)** |

**`aiStack_1dc[113]` 真实常量**：从反编译原文逐条提取（`aiStack_1dc[0xXX]=0xYY` 共 113 条，索引 0~112 全覆盖），落盘 `aiStack_1dc_real.txt`。用途 = 价格/日期→桶 的查找表（索引非单调，是哈希映射，非等宽价格桶）。

---

## 三、COST 反编译

- **`FUN_100cf400`**（1043 行）：基于成本分布数组，遍历找"累计成交量占比 >= frac"的价位
- 数学本质 = `WINNER` 的逆：`COST(frac) = 使 WINNER(P) >= frac 的最小 P`
- 含 `SQRT`(line 449/478) + `"%.3lf"` 格式化(line 450/479) + `LOCK/UNLOCK`(495/498, 925)
- 同样 `FUN_100dd8dc()` 取数据十余次（非纯数学）

---

## 四、筹码分布是谁算的（关键溯源）

- `skbjTemp.dat` 在 dll 内**仅只读引用一次**（line 276 `CFile::Open(...,0x8000=modeRead)`，792 `CFile::Read`）
- 全 dll 搜：`.dat` 文件名仅此一处、`modeWrite/0x4000`/`modeCreate/0x1000` **零出现** → dll 不写筹码源数据
- `FUN_100ccf00` line 402 `CFile::Write` 写的是**另一个 CFile 对象**（WINNER 自身输出缓存，非筹码源）
- 字符串表确认软件身份：`HLTWINNER` `HLTHLP` `HLTFDP` `HLTCHIPS`... 全套 `HLT*` 前缀（**弘历/HongLiTong**），同目录 `sz_updown.dat`(深证) `sh_updown.dat`(上证) `skbjTemp.dat`

**结论：筹码分布 = 弘历行情数据引擎（独立进程/服务）预计算落盘 `skbjTemp.dat`，WINNER/COST 只是读缓存 + 查表。**

→ 对 TV 复现的意义：难点不在 WINNER/COST（只是查表），而在**重建 `skbjTemp.dat` 背后的成本分布算法**——那套算法不在此 dll，很可能源于**服务端下发的日线筹码分布**（呼应 prior：成本类指标真实分布常来自服务端 tick）。

---

## 五、交付物清单（`C:/Users/Administrator/hllevel2_reverse/winner_reverse/`）

### 真实反编译铁证
- `costcore_100ccf00.c` — WINNER 核心 836 行完整反编译
- `costcore_100cf400.c` — COST 核心 1043 行完整反编译
- `aiStack_1dc_real.txt` — `aiStack_1dc[113]` 113 个真实常量（原样 dump）
- `fn_100934f0.c` — WINNER 构造器
- `winner_compute.c` / `vtab_*.c` — vtable 各虚方法
- `WINNER_完整反编译记录.md` — 逐行对应源码算法结构
- `WINNER_算法白皮书.md` — 伪代码白皮书

### 实现（已跑通验证）
- `winner_113.py` — WINNER(P) + 主力筹码分布（ZLCM/SHCM/ZSHTL/ZZLKP），`ZSHTL+ZZLKP=100` 守恒
- `cost_113.py` — COST(frac) + WINNER↔COST 互逆验证（COST(0.5)=106.4→WINNER回查=0.5015）
- `winner_113.pine` — `//@version=5`：WINNER + COST + 主力筹码分布，单一可跑文件

### 辅助脚本
- `parse_bins.py`（提取 aiStack_1dc）、`scan_strings.py`（dll 字符串表）、`_decomp_*.py`（Ghidra 反编译驱动）

---

## 六、诚实标注的未解项

1. **`aiStack_1dc` 哈希映射未完全破解**：它是价格/日期→桶的查找表（line 205-265 是高度优化位运算），实现用等宽 113 桶复刻了"累加+查表"结构，但**未用 aiStack_1dc 做精确桶映射**——那段哈希逻辑静态难读清
2. **`skbjTemp.dat` 上游算法不在本 dll**：成本分布原始计算在弘历数据引擎/服务端，本地 dll 仅查表
3. **COST 里 `%.3lf` 格式化 + `FUN_100ca610` 是结果输出层**，数学核心已对齐，UI 格式化层未深究

---

## 七、可选后续

- A. 继续反 `aiStack_1dc` 哈希映射（价格→桶精确公式，再 2-3 轮）
- B. 反编译上游写 `skbjTemp.dat` 的模块（若在同目录其他 dll）
- C. 打包成开源 GitHub 仓库（Pine + Python + 反编译白皮书）
