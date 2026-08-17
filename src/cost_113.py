# -*- coding: utf-8 -*-
"""
COST(frac) — 对齐 CompMan.dll FUN_100cf400 (WINNER逆运算)

COST = WINNER 的逆运算: 成本分布中累计占比达到 frac 的价位.
dll 铁证: costcore_100cf400.c — 基于成本分布数组找累计占比阈值点.

两个版本 (与 winner_113.py 对应):
  A) 等权版   — 对齐 dll (每根K线等权)
  B) 加权版   — 对齐 TV (成交量加权)
"""
from winner_113 import build, winner_eq, winner_vol, cost_eq, cost_vol

if __name__ == "__main__":
    bars = [
        (20260105, 10.0,10.5, 9.8,10.2,1000),
        (20260106, 10.2,10.8,10.1,10.6,1200),
        (20260107, 10.6,11.0,10.4,10.9,1100),
        (20260108, 10.9,11.2,10.7,11.0,1300),
        (20260109, 11.0,11.5,10.9,11.3,1400),
        (20260112, 11.3,11.8,11.1,11.7,1500),
        (20260113, 11.7,12.0,11.5,11.9,1600),
        (20260114, 11.9,12.3,11.8,12.1,1700),
        (20260115, 12.1,12.5,12.0,12.4,1800),
        (20260116, 12.4,12.8,12.2,12.6,1900),
    ]
    closes, vols = build(bars)
    print("=== COST 验证 (WINNER↔COST 互逆) ===")
    print("[等权] COST(0.1..0.9) =", [round(cost_eq(closes,f),3) for f in (0.1,0.3,0.5,0.7,0.9)])
    print("  回查 WINNER(COST(0.5)) = %.4f" % winner_eq(closes, cost_eq(closes,0.5)))
    print("[加权] COST(0.1..0.9) =", [round(cost_vol(closes,vols,f),3) for f in (0.1,0.3,0.5,0.7,0.9)])
    print("  回查 WINNER(COST(0.5)) = %.4f" % winner_vol(closes,vols, cost_vol(closes,vols,0.5)))
