# aiStack_1dc[13..] 用途 — 最终分析 (2026-08-18)

## 背景
aiStack_1dc[113] 是 FUN_100ccf00 (WINNER) 的常量数组. [0..12] 已确认=平年月度累计天数表.
[13..112] 值非单调(605~661067), 含17个重复, 全正数. 之前误以为是"价格桶表", 已推翻.

## 汇编级证据 (FUN_100ccf00 line 222-264 = 0x100cd600~0x100cd6ba)

```
0x100cd600 cdq / sar eax,1  (算术右移 = /2, 重复 iVar11-2 次)  ← uVar6 位移
0x100cd608 and eax, 0x80000001  (取最低位 &1)
0x100cd614 lea edx, [eax+0x1d]  (uVar10 + 29)
0x100cd617 cmp ebx, edx  (iVar5 <= uVar10+0x1d ?)
0x100cd619 jle 0x100cd635
0x100cd61b mov edx, -0x1d - uVar10; ebx += edx  (iVar5 -= 0x1d+uVar10)
0x100cd624 dec ecx; ...  (iVar11 递减, 内层继续)
...
0x100cd647 mov ecx, [esp+0x28]  (pdVar4 = 收盘价缓冲区)
0x100cd64b fld [ecx]; call dd8dc  (取收盘价)
0x100cd65a mov [edx+ecx*4-4], eax  (local_208[local_234*4-4] = 收盘价)
0x100cd68f mov [edx+ecx*4], 0  (或写 0)
0x100cd69f add edx, 0xc  (pdVar4 += 12)
0x100cd6a8 mov [esp+0x1c], ecx  (local_234++)
0x100cd6b0 jl 0x100cd562  (下一根K线)
```

## 关键发现
1. **local_208 的写入索引始终是 local_234 (K线序号)**, 不是被 aiStack_1dc[13..] 映射的位置.
2. aiStack_1dc[13..] 这段内层循环只做**日期对齐计算**: 把天数序号 iVar5 通过位移+比较
   减到对齐位置, 决定"这根K线是否写入 local_208 / 写0".
3. `0x1d = 29` 暗示**月周期对齐** (每月约29-30天). 结合中文软件背景, 可能是
   **交易日历对齐** (处理周末/停牌/农历, 决定哪些天有数据写入 local_208).

## 交叉验证: COST 不用 aiStack_1dc
grep costcore_100cf400.c: aiStack_1dc 仅出现 0 次 (除 0x1d 别处).
→ aiStack_1dc (含 [13..]) 是 **WINNER 特有的日期对齐表**, COST(价格轴) 不需要.
进一步确认 [13..] ≠ 价格桶表 (否则 COST 也该用).

## 最终结论 (分层)
- [0..12]: 月度累计天数表 — **铁证** (值验证吻合)
- [13..]: 月度日历对齐辅助表 (决定非连续交易日是否写入 local_208) — **推断**
  (证据: 仅WINNER用/COST不用/值非单调/含重复/0x1d月周期特征; 但精确位运算语义未逐位坐实)
- local_208[k] = 第k根K线收盘价(等权), WINNER(P)=成本≤P占比 — **铁证** (汇编确认写入/读取)

## 对实现的影响
winner_113.py 当前用"全部K线等权"模型. dll 实际用 aiStack_1dc[13..] 做**交易日历对齐**
(跳过非交易日写0). 若严格对齐需实现该对齐表, 但差异仅在于"停牌日是否计入" —
对连续交易日数据影响极小. 现有实现方向正确.
