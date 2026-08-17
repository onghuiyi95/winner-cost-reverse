# 重大修正：筹码分布是本地运算（非服务端）

> 日期: 2026-08-18 (推翻前版"服务端算、本地只读"结论)

## 误判原因（诚实交代）
前版结论基于两点, 均被推翻:
1. 误读 `FUN_100ccf00` line 290 `CFile::Open(..., 0x8000)` 为"只读取已算好的分布"
   → 实际 line 205-265 **在该 Open 之前**已从 OHLCV 本地算出 `local_208`
2. 在 EXE 里找不到 skbjTemp 写方 xref → 推"服务端写"
   → 实际 dll 自己也写 skbjTemp.dat (line 400 `0x9001`=modeRead+modeCreate 写回锚点),
     EXE 的 xref=0 是 Ghidra/capstone 工具限制(基址相关引用抓不到), 非真无写方

## 真实流程 (FUN_100ccf00 反编译铁证)

```
line 205-265: 本地计算成本分布 local_208
  - FUN_100dd8dc() 取逐根 K线 OHLCV (本地数据源, 非skbjTemp)
  - iVar5 = aiStack_1dc[iVar11] + 年月日哈希  → 桶索引
  - uVar7 = FUN_100dd8dc() 取成交量 → 写入 local_208[bin]
  - local_234++ 逐根推进

line 276-317: 打开+读 skbjTemp.dat 缓存
  - CFile::Open(..., 0x8000) 读
  - 遍历文件 int 数组, 找 >0x133f073 的值作锚点 local_234 (日期编码)

line 321+: 增量计算 (用锚点对齐历史 + 新K线)

line 400-402: 写回 skbjTemp.dat
  - CFile::Open(..., 0x9001)  [0x9001 = modeRead(0x8000)|modeCreate(0x1000)|0x1]
  - CFile::Write(&local_234, 4)  写回锚点
```

## 修正后结论

**筹码分布 = 本地运算**, `skbjTemp.dat` 是**本地缓存文件**(存锚点/增量, 加速重算),
不是服务端下发.

佐证:
- `FUN_100dd8dc()` 是本地 OHLCV 数据源, line 205-265 从它逐根算 local_208 (核心计算在本地)
- dll 自己对 skbjTemp.dat 既读(0x8000)又写(0x9001)
- "服务端算"假设被推翻: 无证据表明分布来自网络; 所有计算逻辑在本地 dll

## 对 TV 复现的意义 (更新)

WINNER/COST 不仅"查表", 其核心 **local_208 累加** (line 205-265) 是本地从 OHLCV
重建成本分布 — 这恰是 TV 标准 WINNER 的做法 (基于本地 OHLCV 算成本分布).
之前 winner_113.py 用本地 OHLCV 重建 113 桶分布, 方向正确,
且现在确认: **无需服务端数据, 纯本地 OHLCV 即可复现** (与 dll 算法本质一致).

待澄清: `aiStack_1dc` 哈希映射 (line 213-215, 年月日→桶索引) 仍未完全破解,
winner_113 用等宽桶近似; 若破解该映射, 可 100% 对齐 dll 桶边界.
