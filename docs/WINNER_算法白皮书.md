# WINNER 函数 — 真实反编译算法白皮书 (CompMan.dll)

> 工具: Ghidra 12.1.2 + JDK17 (pyghidra) / `CompMan.dll` (预测大师, md5 37d3026f...)
> 核心函数: `FUN_100ccf00` (836行反编译, 成本分布核心) @ `costcore_100ccf00.c`
> 逆向日期: 2026-08-17

## 一、函数定位铁证
WINNER 派生类 vtable `PTR_WINNER_IMPL_1015e7f8` 的 compute 路径最终调用 `FUN_100ccf00`——
它加载 `skbjTemp.dat`(筹码分布文件)、`FUN_100dd8dc()`(取OHLCV)、用 **113 档价格桶表** `aiStack_1dc[113]` 累加成交量, 输出成本分布数组。

## 二、反编译源码提取的真实算法结构 (FUN_100ccf00)

```c
double* FUN_100ccf00(double* out, int stock, int p3, int p4) {
  // 1) 校验股票数据对象存在 (FUN_1009e2d0), 否则返回 _DAT_1019167c(默认)
  // 2) 校验代码前缀 "1A0001" (沪市A股), 否则返回默认
  // 3) 初始化 113 档成本分布价格桶表 aiStack_1dc[113]
  //    (值如 0x2b6=694, 0xb55=2901, 0x5164b=333387 ... 各档成本价位/累计量)
  // 4) 加载 skbjTemp.dat 读已有成本分布缓存
  // 5) 双层循环 (line 205-265):
  for (每根K线 i in 0..local_230) {
      iVar5 = FUN_100dd8dc();              // 取该K线 OHLCV+日期
      year  = iVar5 / 10000;
      month = (iVar5 % 10000) / 100;
      // 按价格档位 iVar11 查桶 aiStack_1dc, 累加成交量到 local_208[bin]
      local_208[i] = 成交量;               // 每档累计成交量
  }
  // 6) 后处理累加 (line 318-399): 把 local_208 的成交量累加成占比 local_228/local_234
  // 7) WINNER 查表 (line 405-431) — 核心:
  //    找价格 P 对应的桶 bin, 从 0 累加到 bin 的成交量计数:
  do {
      if (0 < local_208[bin]) uVar6++;     // 累计 <=P 的档数/量
      bin--;
  } while (bin >= 0);
  //    uVar6 / 总档(量) = WINNER(P)  // 价格<=P 的累计占比
  // 8) 输出 double* (占比 0~1)
}
```

## 三、算法伪代码 (对照 TV 报错逐行核对)
```pascal
// WINNER(P): 成本分布获利盘比例
// 输入: 日线 OHLCV, 全历史
const BINS = 113                     // aiStack_1dc[113] 档数
binPrice[1..113] = {...}             // 113 档成本价位表 (dll 内置常量)
vol[1..113] = 0                      // 每档累计成交量

// 1) 建成本分布
for i = 0..N-1:                      // 每根K线 (FUN_100dd8dc)
    p = CLOSE[i]                     // 该K线成本(收盘价)
    b = binIndex(p, binPrice)        // 落入哪档 (aiStack_1dc 查表)
    vol[b] = vol[b] + VOL[i]         // 累加成交量 (local_208)

// 2) WINNER(P)
total = SUM(vol[1..113])
cum = SUM(vol[1..binIndex(P)])      // 价格<=P 的累计量 (line 405 累加)
WINNER(P) = cum / total             // 0~1

// 主力筹码/小筹码 (原式)
ZLCM  = EMA(WINNER(CLOSE)*70, 3)
SHCM  = EMA((WINNER(CLOSE*1.1)-WINNER(CLOSE*0.9))*80, 3)
ZSHTL = SHCM/(ZLCM+SHCM)*100
ZZLKP = ZLCM/(ZLCM+SHCM)*100
```

## 四、关键差异 (vs 之前 naive 版)
| 项 | 之前 naive | dll 真实 |
|---|---|---|
| 成本分布 | 逐根按收盘价直接累加 | **113 档价格桶** 离散化后再累加 |
| 桶表 | 无 | `aiStack_1dc[113]` dll 内置常量 |
| 数据 | 直接用 OHLCV | 经 `skbjTemp.dat` 缓存 + `FUN_100dd8dc` 取 |
| 查表 | 逐根比较 | 桶索引 + 桶内累加 (line 405-431) |

数值结果两者近似 (都收敛到"价格<=P占比"), 但 dll 用 113 桶离散化, 精度由桶宽决定.

## 五、文件
- `winner_reverse/costcore_100ccf00.c` — 836行完整反编译 (铁证)
- `winner_reverse/costcore_100cf400.c` — 1043行 (COST 相关核心)
- `winner_reverse/winner_compute.c` — WINNER 派生类析构 (含 vtable 名)
- `winner_reverse/WINNER_逆向记录.md` — 总记录
- `winner_pine.pine` / `winner.py` — 实现 (建议改用113桶模型)
