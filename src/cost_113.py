# -*- coding: utf-8 -*-
"""
COST(frac) — 成本分布价位函数 (对齐 CompMan.dll FUN_100cf400 真实反编译)

dll 铁证 (costcore_100cf400.c, 1043行):
  - 基于成本分布数组 (local_208 等价), 找"累计成交量占比 >= frac"的价位
  - 即 WINNER 的逆运算: COST(frac) = 使 WINNER(P) >= frac 的最小 P
  - 原函数: 遍历成本分布找 min/max (line 250-260), 比较累计量定位阈值点 (line 380-385)

标准弘历/通达信: COST(X) = 成本分布中累计占比达到 X% 的价位.
  等价于: 把成交量按价格升序累加, 找到累计量/总量 >= X/100 的那一档价格.

本实现对齐 dll: 复用 winner_113 的 CostDist 成本分布, COST = 逆查表.
"""
import numpy as np
from winner_113 import CostDist, N_BINS

def cost(cd, frac):
    """COST(frac): 累计占比 >= frac 的价位 (frac 0~1, 对齐 dll FUN_100cf400).
    即 WINNER 的逆: 找到最小价位 P 使 WINNER(P) >= frac."""
    if cd.total <= 0:
        return cd.lo
    target = frac * cd.total
    cum = 0.0
    for b in range(cd.n):
        cum += cd.vol[b]
        if cum >= target:
            # 该档中心价位
            return cd.lo + (b + 0.5) / cd.n * (cd.hi - cd.lo)
    return cd.hi

def cost_series(closes, vols, frac, lookback=None):
    cd = CostDist().build(closes, vols, lookback)
    return cost(cd, frac)

# ---- 主力筹码原式中用到的 COST 衍生 (若需要) ----
# 原式未直接用 COST, 但 WINNER 是 COST 的累积分布函数.
# 这里顺带给出 COST(10)/COST(50)/COST(90) 等常见价位输出.

if __name__ == "__main__":
    import numpy as np
    rng = np.random.default_rng(20260817)
    n = 400
    close = 100 + np.cumsum(np.sin(np.arange(n) / 8.0)) * 0.8 + rng.normal(0, 0.5, n)
    close = np.maximum(close, 5)
    vol = 1e6 * (0.6 + 0.4 * np.abs(np.sin(np.arange(n) / 5.0)))
    cd = CostDist().build(close, vol)

    # 验证: COST(frac) 应与 WINNER 互逆
    print("=== COST(frac) 与 WINNER 互逆验证 ===")
    for f in (0.1, 0.3, 0.5, 0.7, 0.9):
        p = cost(cd, f)
        w = cd.winner(p)
        print("  COST(%.1f)=%.3f  -> WINNER(该价)=%.4f (应≈%.1f)" % (f, p, w, f))

    # 常用成本价位
    print("\n=== 常用成本分布价位 ===")
    print("  成本10%%: %.3f" % cost(cd, 0.10))
    print("  成本50%% (筹码中线): %.3f" % cost(cd, 0.50))
    print("  成本90%%: %.3f" % cost(cd, 0.90))
    print("  当前价:  %.3f" % close[-1])
