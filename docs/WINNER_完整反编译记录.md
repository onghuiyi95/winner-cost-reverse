# WINNER 函数 — 完整反编译记录 (CompMan.dll FUN_100ccf00)

> 工具: Ghidra 12.1.2 + JDK17 (pyghidra) / `CompMan.dll` (预测大师)
> 核心函数: `FUN_100ccf00` (836行反编译, `costcore_100ccf00.c`)
> 日期: 2026-08-17

## 一、真实反编译的算法结构 (逐行对应源码)

```c
double* FUN_100ccf00(double* out, int stock, int p3, int p4) {
  // 1) 校验股票数据 (FUN_1009e2d0), 校验代码前缀 "1A0001" (沪市)
  // 2) 局部数组 aiStack_1dc[113] — 反编译提取真实常量 (见 aiStack_1dc_real.txt)
  //    注: 该表索引非价位排序 ([2]=31,[3]=59,[13]=2635,[14]=333387...),
  //        实际是 价格/日期->桶 的查找表或参数表, 非直接价格桶边界.
  // 3) 读 skbjTemp.dat (成本分布缓存) + FUN_100dd8dc() 取 OHLCV
  // 4) 双层循环 (line 205-265): 逐根K线, 用 aiStack_1dc 映射 + 日期分解,
  //    把成交量累加进 local_208[bin] (成本分布累积数组)
  // 5) 后处理 (line 318-399): local_208 累加 -> local_228 (累计占比)
  // 6) WINNER 查表 (line 405-431) — 核心累加:
  //    bin = 价格P对应的桶; do { if (local_208[bin]>0) uVar6++; bin--; } while(bin>=0)
  //    WINNER(P) = uVar6 / 总桶
  // 7) 返回 double* (占比 0~1)
}
```

## 二、WINNER(P) 的真实计算 (对齐 line 405-431)

WINNER 不是"等宽价格桶", 而是:
  - 成本分布数组 `local_208[bin]` (bin = 0..N, 由 aiStack_1dc 映射 + 日期分解决定)
  - `WINNER(P) = (价格<=P 的桶数累加) / 总桶数`

我方 Python/Pine 用真实逻辑复刻:
  - `local_208` = 逐根累加的成交量分布 (build)
  - `WINNER(P)` = 从0累加到目标桶的占比 (winner)

## 三、COST(frac) 真实算法 (对齐 FUN_100cf400, 1043行反编译)
COST = WINNER 的逆运算: **成本分布中累计成交量占比达到 frac 的价位**.
dll 逻辑 (costcore_100cf400.c):
  - 基于成本分布数组 (local_208 等价), 遍历找 min/max + 比较累计量定位阈值点 (line 250-260, 380-385)
  - 数学本质: 把成交量按价格升序累加, 找到 累计量/总量 >= frac 的那一档价位
实现见 `cost_113.py` / `winner_113.pine` (costP 函数). 验证: COST(0.5)=106.4 -> WINNER(该价)=0.5015.

## 四、aiStack_1dc[113] 真实常量 (从反编译提取, 原样)
见 `aiStack_1dc_real.txt`. 用途: 价格/日期 -> 桶索引 的查找表 (非等宽价格桶).
因为索引非单调, 无法直接当价位边界用; dll 用它做哈希映射.

## 四、文件
- `costcore_100ccf00.c` — 836行完整反编译 (铁证)
- `costcore_100cf400.c` — 1043行 COST 核心
- `aiStack_1dc_real.txt` — 113 个真实常量 (原样dump)
- `winner_113.py` / `winner_113.pine` — 对齐 dll 真实查表逻辑的实现
- `WINNER_算法白皮书.md` — 算法伪代码
