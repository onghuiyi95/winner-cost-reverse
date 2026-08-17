# -*- coding: utf-8 -*-
"""
WINNER(P) / COST(frac) — 对齐 CompMan.dll (FUN_100ccf00 / FUN_100cf400)

dll 铁证 (汇编级):
  pdVar4: 每根K线 12字节 = 3 float, [+0]=收盘价(成本), [+0xc]=日期
  local_208[k] = 第k根K线收盘价
  WINNER(P) = 成本 <= P 的占比
  COST(frac) = WINNER 的逆运算 (累计占比达 frac 的价位)

两个版本:
  A) 等权版 (equal_weight)    — 对齐 dll 真实结构 (每根K线等权)
  B) 成交量加权版 (vol_weight) — 对齐 TV 标准 WINNER (按成交量加权)

bars = [(date_int, open, high, low, close, vol), ...]   date_int=YYYYMMDD
"""
# aiStack_1dc[0..12] = 平年月度累计天数 (已验证)
MONTH_DAYS = [0,0,31,59,90,120,151,181,212,243,273,304,334]

def date_to_daynum(yyyymmdd):
    """dll line 213-215 哈希: 年月日 -> 距基准日天数序号 (0x16d=365, 0x781=1921)"""
    y = yyyymmdd // 10000
    m = (yyyymmdd % 10000) // 100
    d = yyyymmdd % 100
    yb = y - 0x781
    return MONTH_DAYS[m] + (yb + (1 if yb >= 0 else 0))//4 + y*0x16d - 0xab313 + d

def build(bars):
    closes = [b[4] for b in bars]
    vols   = [b[5] for b in bars]
    return closes, vols

# ---------- A) 等权版 (对齐 dll) ----------
def winner_eq(closes, P):
    """WINNER(P) = 成本 <= P 的K线占比 (等权)"""
    if not closes: return 0.0
    return sum(1 for c in closes if c <= P) / len(closes)

def cost_eq(closes, frac):
    """COST(frac) = 累计占比达 frac 的价位 (等权, WINNER逆运算)"""
    if not closes: return 0.0
    s = sorted(closes)
    idx = max(0, min(len(s)-1, int(frac*len(s)+0.5)-1))
    return s[idx]

# ---------- B) 成交量加权版 (对齐 TV) ----------
def winner_vol(closes, vols, P):
    """WINNER(P) = 成本 <= P 的累计成交量占比 (加权)"""
    if not closes: return 0.0
    tot = sum(vols)
    if tot <= 0: return winner_eq(closes, P)
    return sum(v for c,v in zip(closes,vols) if c <= P) / tot

def cost_vol(closes, vols, frac):
    """COST(frac) = 累计成交量占比达 frac 的价位 (加权, WINNER逆运算)"""
    if not closes: return 0.0
    pairs = sorted(zip(closes, vols))
    tot = sum(v for _,v in pairs)
    cum = 0.0
    for c,v in pairs:
        cum += v
        if cum/tot >= frac:
            return c
    return pairs[-1][0]

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
    cn = closes[-1]
    print("=== A) 等权版 (对齐 dll) ===")
    print("WINNER(%.1f)=%.4f  WINNER(11.0)=%.4f" % (cn, winner_eq(closes,cn), winner_eq(closes,11.0)))
    cf = cost_eq(closes,0.5)
    print("COST(0.5)=%.3f -> WINNER回查=%.4f" % (cf, winner_eq(closes,cf)))
    print("\n=== B) 成交量加权版 (对齐 TV) ===")
    print("WINNER(%.1f)=%.4f  WINNER(11.0)=%.4f" % (cn, winner_vol(closes,vols,cn), winner_vol(closes,vols,11.0)))
    cfv = cost_vol(closes,vols,0.5)
    print("COST(0.5)=%.3f -> WINNER回查=%.4f" % (cfv, winner_vol(closes,vols,cfv)))
