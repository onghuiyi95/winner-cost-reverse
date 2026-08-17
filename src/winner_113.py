# -*- coding: utf-8 -*-
"""
WINNER(P) / COST(frac) — 对齐 CompMan.dll FUN_100ccf00 / FUN_100cf400 真实结构

dll 铁证 (汇编级确认):
  pdVar4 缓冲区: 每根K线 = 12字节 = 3个float
    [+0x0] = 收盘价(成本)  -> local_208[k] = 取整后的收盘价
    [+0xc] = 日期编码
  local_208[k] = 第k根K线的收盘价(成本)
  WINNER(P) = 统计 local_208 中 <= P 的数量占比 (等权)
            = "历史上成本 <= P 的K线占比" = 标准成本分布定义
  COST(frac) = WINNER 的逆运算: 使累计占比达 frac 的价位

注意: dll 用每根K线等权; TV标准WINNER用成交量加权. 这是唯一差异.
本实现按 dll 真实结构 (等权每根K线收盘价).

用法: bars = [(date_int, open, high, low, close, vol), ...]
  date_int 格式如 20260818 (YYYYMMDD)
"""
# aiStack_1dc[0..12] = 平年月度累计天数 (已验证)
MONTH_DAYS = [0,0,31,59,90,120,151,181,212,243,273,304,334]

def date_to_daynum(yyyymmdd):
    """dll line 213-215 哈希: 年月日 -> 距基准日天数序号 (0x16d=365, 0x781=1921)"""
    y = yyyymmdd // 10000
    m = (yyyymmdd % 10000) // 100
    d = yyyymmdd % 100
    yb = y - 0x781
    base = MONTH_DAYS[m] + (yb + (1 if yb >= 0 else 0))//4 + y*0x16d - 0xab313 + d
    return base

def build_local208(bars):
    """local_208[k] = 第k根K线的收盘价(成本)  (dll: 取整后存入, 这里直接用float)"""
    return [b[4] for b in bars]  # close

def winner_p(local208, P):
    """WINNER(P) = 成本 <= P 的K线占比 (等权)"""
    if not local208: return 0.0
    n = len(local208)
    cnt = sum(1 for c in local208 if c <= P)
    return cnt / n

def cost_frac(local208, frac):
    """COST(frac) = 使累计占比达 frac 的价位 (WINNER逆运算)"""
    if not local208: return 0.0
    s = sorted(local208)
    idx = int(frac * len(s) + 0.5) - 1
    idx = max(0, min(len(s)-1, idx))
    return s[idx]

def main_chip(local208, close_now):
    """主力筹码分布 ZLCM/SHCM/ZSHTL/ZZLKP (用户原式, 用 dll 的 WINNER 替代)"""
    Wc = winner_p(local208, close_now)
    Wc_low = winner_p(local208, close_now*0.9)
    Wc_high = winner_p(local208, close_now*1.1)
    def ema(vals, a=0.5):
        out=[]; prev=vals[0] if vals else 0
        for v in vals:
            prev = a*v + (1-a)*prev
            out.append(prev)
        return out[-1] if out else 0
    zlcm = ema([Wc*70]*3) if local208 else 0
    shcm = ema([(Wc_high-Wc_low)*80]*3) if local208 else 0
    tot = zlcm+shcm
    if tot <= 0: return 0,0,0,0
    zshtl = shcm/tot*100
    zzlkp = zlcm/tot*100
    return zlcm, shcm, zshtl, zzlkp

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
    L = build_local208(bars)
    cn = bars[-1][4]
    print("=== 对齐 dll 真实结构 (local_208=每根收盘价, WINNER=等权占比) ===")
    print("WINNER(CLOSE=%.1f) = %.3f" % (cn, winner_p(L, cn)))
    print("WINNER(11.0) = %.3f" % winner_p(L, 11.0))
    cf = cost_frac(L,0.5)
    print("COST(0.5) = %.3f  -> WINNER回查 = %.3f" % (cf, winner_p(L, cf)))
    zlcm,shcm,zshtl,zzlkp = main_chip(L, cn)
    print("ZLCM=%.2f SHCM=%.2f ZSHTL=%.2f ZZLKP=%.2f (和=%.2f)" % (zlcm,shcm,zshtl,zzlkp, zshtl+zzlkp))
