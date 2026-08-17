# Quantum Terminal Pro CYQ 算法分析 (2026-08-18)

## 来源
用户提供的 web app 源码 (index.html + app.js, "Quantum Terminal Pro").
app.js 内含完整 CYQ 筹码分布实现: drawCyqCanvas() + getCyqState().

## 算法铁证 (逐行对齐 app.js)
```
lookback = 150                          // 截止日前150根滚动窗口
numBuckets = 80                         // 价格桶数
avgPrice = (high+low+close)/3           // 当日成本取价
daysAgo = window.length-1-i
weight = Math.pow(0.96, daysAgo)         // 衰减: 每日保留96%
adjVol = (volume||1) * weight
buckets[bIdx] += adjVol                  // 成交量加权累加到价格桶
totalVol += adjVol
profitVol = Σ buckets[i] where 桶价 <= 当前收盘
获利盘% = profitVol/totalVol*100
套牢盘% = 100 - 获利盘%
平均成本 = Σ(桶价*buckets[i]) / Σbuckets[i]
```

## 分色 (drawCyqCanvas)
- 成本 <= 当前收盘: 红 rgba(242,54,69)  (获利盘红)
- 成本 > 当前收盘: 绿 rgba(8,153,129)   (套牢盘绿)
- 注: 此app红=获利, 与通达信(黄=获利)配色相反但逻辑同

## 三态信号 (getCyqState)
取窗口上下30%区间的成交量占比:
- topVolPct >= 62 -> RED (高位密集危險)
- bottomVolPct >= 62 -> PURPLE (低位密集安全)
- 否则 YELLOW (常态)
状态切换: PURPLE->YELLOW=空转多(买), RED->YELLOW=多转空(卖)

## 与我们逆向的弘历 dll 对比
| 参数 | Quantum app | 弘历 dll FUN_008d9950 |
|---|---|---|
| 成本取价 | (H+L+C)/3 | (H+L)/2 或收盘 |
| 衰减 | 0.96^daysAgo (每日96%) | 0.96~0.99 (量级一致) |
| 桶数 | 80 | 1000 (dll) / 11151 (全局) |
| 窗口 | 150滚动 | 全历史 (skbjTemp) |
| 获利判定 | 成本<=当前收盘 | 成本<=当前价 |

## 对齐用户原版图 (93.88%)
用户图: 成本分布日期20210312 / 当前价8.97 / 获利93.88%
复现(新浪浦发600000):
- 全历史 decay0.96: 99.91%
- 全历史 decay0.99: 91.85%  <- 接近93.88%
- 150窗口 decay0.96: 100.00% (app默认)
=> 用户图=全历史 + decay≈0.99 (app默认150窗口给100%不符, 说明原版用全历史)

## 结论
三套(弘历dll/Quantum app/用户原图)CYQ算法同源:
  成交量加权 + 指数衰减 + 成本<=当前价占比
差异仅衰减系数/窗口/成本取价微调
decay≈0.99 全历史可对齐用户图93.88%
