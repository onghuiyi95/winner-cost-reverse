# pdVar4 缓冲区字段语义 — 汇编级确认 (2026-08-18)

## 铁证: 汇编直接看 FLD 源 (绕过 Ghidra ST0 隐藏)

反汇编 FUN_100ccf00 里三处 call FUN_100dd8dc (0x100dd8dc = 浮点取整),
看调用前 FLD 压入 ST0 的内存源:

### line 208 (0x100cd566) — 取日期
```
0x100cd562 mov eax, [esp+0x28]        ; eax = pdVar4 (local_228)
0x100cd566 fld qword ptr [eax + 0xc]  ; ST0 = *(pdVar4 + 12)  ← 偏移 12 (0xc)
0x100cd569 call 0x100dd8dc           ; iVar5 = ROUND(*(pdVar4+12))  = 日期编码
```

### line 242 (0x100cd64b) — 写 local_208
```
0x100cd647 mov ecx, [esp+0x28]        ; ecx = pdVar4
0x100cd64b fld qword ptr [ecx]        ; ST0 = *(pdVar4 + 0)   ← 偏移 0
0x100cd64d call 0x100dd8dc
0x100cd65a mov [edx+ecx*4-4], eax     ; local_208[local_234*4 - 4] = 取整值
```

### line 250 (0x100cd672) — 写 local_208
```
0x100cd66e mov eax, [esp+0x28]
0x100cd672 fld qword ptr [eax]        ; ST0 = *(pdVar4 + 0)   ← 偏移 0
0x100cd674 call 0x100dd8dc
0x100cd... mov [edx+ecx*4], eax        ; local_208[local_234*4] = 取整值
```

## 结论 (铁证级)

pdVar4 缓冲区: **每根K线 = 12字节 = 3个 float**
- [+0x0]  = line 242/250 取整写入 local_208 的字段 = **价格/成本 (收盘价)**
- [+0xc]  = line 208 取作日期编码 = **日期**
- [+0x4]/[+0x8] = 第三个字段 (推测成交量或OHLC其余, 待确认)

local_208[k] = 第k根K线的 **收盘价(成本)** (取整后).
WINNER(P) = 统计 local_208 中 ≤P 的数量占比 = "历史上成本≤P的K线占比"
           = 标准成本分布定义 (dll 用每根K线等权; TV用成交量加权, 是唯一差异).

## 之前 winner_113.py 的错误
用"113桶累加成交量"模型 — 结构上和 dll 不同.
dll 实际: local_208[k]=每根K线收盘价, WINNER(P)=成本≤P的K线数/总数 (等权).

## 修正实现方向
winner_113.py 应改为:
  local_208 = [close[k] for k in range(N)]   # 每根K线收盘价
  WINNER(P) = count(close[k] <= P) / N       # 等权占比
  COST(frac) = 使累计占比达 frac 的价位
(这正是 TV 标准 WINNER 的等权版, 与 dll 本质一致)
