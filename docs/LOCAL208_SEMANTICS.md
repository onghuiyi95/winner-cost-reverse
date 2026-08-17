# local_208 / FUN_100dd8dc 语义追踪 (2026-08-18)

## 关键修正: FUN_100dd8dc 不是数据源!

反编译 FUN_100dd8dc (27行, entry 0x100dd8dc):
```c
ulonglong FUN_100dd8dc(void) {
  uVar1 = (ulonglong)ROUND(in_ST0);   // 取浮点参数 ST0
  ... 整数四舍五入/截断 ...
  return uVar1;                        // 返回整数
}
```
→ **这只是浮点→整数转换辅助函数**. 真正的 OHLCV 数据来自调用它之前压入 ST0 的值
(来自 pdVar4 等数据缓冲区), 不是这个函数获取的.

所以 "确认 FUN_100dd8dc 返回价格还是量" 的前提是错的 — 它不返回数据, 它转换数据.
真正数据在 pdVar4/pdVar12/pdVar19 这些**数据缓冲区指针**.

## 数据缓冲区结构 (铁证)

COST (FUN_100cf400) 和 WINNER (FUN_100ccf00) 里, 数据指针统一用 **+0xc (12字节)**
步进:
- `pdVar12 = (double*)((int)pdVar12 + 0xc)` (costcore_100cf400.c line 387)
- `local_228 = ... (uint)local_228 + 0xc` (costcore_100ccf00.c line 254)

→ **每根K线 = 12字节 = 3个 float 字段** (非完整 OHLCV 20字节).
可能存 (收盘价, 成交量, 日期编码) 或 (收/高/低) 变体.

## COST 核心逻辑 (costcore_100cf400.c line 371-392)
```c
iVar11 = FUN_100dd8dc();              // 循环计数(取整)
do {
  iVar11 = FUN_100dd8dc();
  dVar2 = *pdVar12;                    // 取当前K线价格(double)
  if (dVar2 < uStack_190 && dVar2 < *pdVar12窗口上界 && dVar2 < *pdVar12窗口下界) {
    pdStack_1a4 = pdVar21;            // 记录位置
    uStack_190 = dVar2;               // 更新最小
  }
  pdVar12 += 0xc;                     // 下一根
} while (pdVar21 <= pdVar30);
*(puStack_114 + pdStack_1a4*3) = _DAT_1015af08;  // 写结果
```
→ 对每根目标K线, 遍历其历史窗口(往前 N 根), 找**窗口内价格最小的位置**,
写常量结果. 这是"过去N根最低价位置"类计算 (支撑/低点检测).

## WINNER 占比统计 (costcore_100ccf00.c line 405-431)
```c
do {
  if (*(local_208 + puVar13*4) > 0) uVar6++;   // 统计 local_208 中正数个数
  puVar13 -= 1;
} while (puVar13 >= 0);
```
→ local_208 是**按K线序号的时间序列数组**, WINNER 统计其中满足条件的数量占比.
local_208[k] 存的字段 = FUN_100dd8dc() 第二次调用写入的值 (line 242/250).

## 待确认 (100%对齐必需)
1. pdVar4 缓冲区的 3 个 float 字段语义 (收? 量? 日期?)
2. WINNER(P): local_208[k] 存什么 + 怎么和 P 比较算占比 (line 405-431 后续除法)
3. 反编译 FUN_1009e2d0 (line 201 准备数据对象) 确认字段语义

## 验证路线建议
与其继续在 Ghidra 里抠 ST0 隐藏的输入字段 (反编译看不到 FUN_100dd8dc 前压了 pdVar4 哪个字段),
不如**用弘历真实 WINNER 渲染值做 MAE 校准** (用户一贯标准):
- 现有 winner_113.py 113桶模型已跑通 ZSHTL+ZZLKP=100 守恒
- 但和 dll 真实值差多少需真实值比对才能定方向
