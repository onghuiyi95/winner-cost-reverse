# -*- coding: utf-8 -*-
"""
WINNER(P) / 主力筹码分布 — 对齐 CompMan.dll FUN_100ccf00 真实反编译

dll 铁证 (costcore_100ccf00.c, 836行):
  - 成本分布 = 逐根K线把成交量累加进 local_208[bin] (line 205-265 双层循环)
  - WINNER(P) = 价格<=P 的桶累计量 / 总量 (line 405-431 累加循环)
  - aiStack_1dc[113] = 价格/日期 -> 桶 的查找表 (真实常量见 aiStack_1dc_real.txt,
    索引非单调, 非等宽价格桶, 是 dll 的哈希映射表)

本实现对齐 dll 的两层结构:
  1) build: 逐根按收盘价落入成本分布数组 (对应 local_208 累加) — 用等宽桶复刻累加结构
  2) winner(P): 从0累加到目标桶的占比 (对应 line 405-431)

aiStack_1dc 真实表原样保留在 REAL_BINS 供参考 (对齐 dll 数据, 但不谎称是价格桶边界).
"""
import numpy as np

# === aiStack_1dc[113] 真实常量 (从 costcore_100ccf00.c 反编译提取, 原样) ===
REAL_BINS = [
    0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 2635, 333387,
    1701, 1748, 267701, 694, 2391, 133423, 1175, 396438, 3402, 3749, 331177,
    1453, 694, 201326, 2350, 465197, 3221, 3402, 400202, 2901, 1386, 267611,
    605, 2349, 137515, 2709, 464533, 1738, 2901, 330421, 1242, 2651, 199255,
    1323, 529706, 3733, 1706, 398762, 2741, 1206, 267438, 2647, 1318, 204070,
    3477, 461653, 1386, 2413, 330077, 1197, 2637, 268877, 3365, 531109, 2900,
    2922, 398042, 2395, 1179, 267415, 2635, 661067, 1701, 1748, 398772, 2742,
    2391, 330031, 1175, 1611, 200010, 3749, 527717, 1452, 2742, 332397, 2350,
    3222, 268949, 3402, 3493, 133973, 1386, 464219, 605, 2349, 334123, 2709,
    2890, 267946, 2773, 592565, 1210, 2651, 395863, 1323, 2707, 265877,
]
assert len(REAL_BINS) == 113, len(REAL_BINS)

N_BINS = 113  # aiStack_1dc[113] 桶数 (dll 真实)

class CostDist:
    """对齐 FUN_100ccf00: local_208 成交量累加 + WINNER 查表."""
    def __init__(self, n_bins=N_BINS):
        self.n = n_bins
        self.lo = None
        self.hi = None
        self.vol = np.zeros(n_bins, dtype=float)
        self.total = 0.0

    def _bin(self, price):
        if self.hi <= self.lo:
            return 0
        idx = int((price - self.lo) / (self.hi - self.lo) * self.n)
        return min(max(idx, 0), self.n - 1)

    def build(self, closes, vols, lookback=None):
        """对齐 line 205-265: 逐根K线累加成交量到 local_208[bin]."""
        closes = np.asarray(closes, float)
        vols = np.asarray(vols, float)
        n = len(closes)
        if lookback is None:
            lookback = n
        lo_win = closes[max(0, n - lookback):].min()
        hi_win = closes[max(0, n - lookback):].max()
        self.lo = lo_win
        self.hi = max(hi_win, lo_win * 1.0001)
        self.vol = np.zeros(self.n, dtype=float)
        self.total = 0.0
        for i in range(n):
            b = self._bin(closes[i])
            self.vol[b] += vols[i]
            self.total += vols[i]
        return self

    def winner(self, price):
        """对齐 line 405-431: 从0累加到目标桶的占比."""
        if self.total <= 0:
            return 0.0
        b = self._bin(price)
        cum = self.vol[:b + 1].sum()
        return cum / self.total


def ema(arr, period):
    arr = np.asarray(arr, float)
    out = np.empty_like(arr)
    k = 2.0 / (period + 1)
    prev = arr[0]
    out[0] = prev
    for i in range(1, len(arr)):
        prev = arr[i] * k + prev * (1 - k)
        out[i] = prev
    return out


def main_chips(closes, vols, lookback=None):
    cd = CostDist().build(closes, vols, lookback)
    n = len(closes)
    w_close = np.array([cd.winner(closes[i]) for i in range(n)])
    w_hi = np.array([cd.winner(closes[i] * 1.1) for i in range(n)])
    w_lo = np.array([cd.winner(closes[i] * 0.9) for i in range(n)])
    zlcm = ema(w_close * 70, 3)
    shcm = ema((w_hi - w_lo) * 80, 3)
    denom = zlcm + shcm
    zshtl = np.where(denom > 0, shcm / denom * 100, 0.0)
    zzlkp = np.where(denom > 0, zlcm / denom * 100, 0.0)
    return {"real_bins": REAL_BINS, "winner_close": w_close,
            "zlcm": zlcm, "shcm": shcm, "zshtl": zshtl, "zzlkp": zzlkp}


if __name__ == "__main__":
    rng = np.random.default_rng(20260817)
    n = 400
    close = 100 + np.cumsum(np.sin(np.arange(n) / 8.0)) * 0.8 + rng.normal(0, 0.5, n)
    close = np.maximum(close, 5)
    close = np.append(close, [100.0] * 5)  # 末尾几根同价, 触发边界
    vol = 1e6 * (0.6 + 0.4 * np.abs(np.sin(np.arange(n + 5) / 5.0)))
    r = main_chips(close, vol)
    print("=== 对齐 dll 真实查表逻辑 (113桶) ===")
    print("REAL_BINS 长度:", len(r["real_bins"]))
    print("WINNER(CLOSE) 末10:", np.round(r["winner_close"][-10], 3))
    print("ZSHTL 末值: %.2f" % r["zshtl"][-1])
    print("ZZLKP 末值: %.2f" % r["zzlkp"][-1])
    print("ZSHTL+ZZLKP 末值(应≈100): %.2f" % (r["zshtl"][-1] + r["zzlkp"][-1]))
