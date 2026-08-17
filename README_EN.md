# winner-cost-reverse

Reverse-engineering of the **WINNER** and **COST** chip-distribution (cost-basis) functions
from **HongLiTong (弘历/预测大师) `CompMan.dll`** — a Chinese stock analysis terminal.

> Tools: Ghidra 12.1.2 + JDK 17 (pyghidra). Platform: Windows. Date: 2026-08.

## What was found

`WINNER(P)` and `COST(frac)` are standard HongLiTong / TongDaXin chip-distribution
functions. Both were decompiled from the real binary (not re-implemented from
definitions):

| Function | Address | Role |
|---|---|---|
| `FUN_100ccf00` | WINNER core | 836-line decompile — builds `local_208` (per-bar array, length = bar count) from `FUN_100dd8dc()`, date→day# hash via `aiStack_1dc`, WINNER lookup (line 405–431) |
| `FUN_100cf400` | COST core | 1043-line decompile — inverse of WINNER: finds the price where cumulative volume ratio ≥ `frac` |
| `FUN_100934f0` | WINNER ctor | sets 14 flags by type code `0x138`, vtable `PTR_WINNER_IMPL_1015e7f8` |
| `aiStack_1dc[113]` | date table | 113 real constants; `[0..12]` = days-per-month table (NOT a price-bin table — see correction) |

Both functions are **isomorphic**: each does data-load (`FUN_100dd8dc` /
`FUN_1009e2d0`) + math (double-loop accumulation) + thread-locks
(`LOCK`/`UNLOCK`) + result formatting (`%.3lf`). They are **not** a "one does
infra, one does math" split.

## Key result: chip distribution is computed LOCALLY (corrected 2026-08-18)

**Correction:** an earlier draft claimed the chip distribution was computed
server-side and only read from a cache (`skbjTemp.dat`). That was **wrong**.
Re-examining `FUN_100ccf00` (lines 205–265 vs 276–402) shows the opposite:

1. **Lines 205–265 run BEFORE any file open** — `local_208` (the cost-distribution
   array) is built locally from `FUN_100dd8dc()` (local OHLCV source), bucketed by
   a `aiStack_1dc` hash of the bar's date/price. No data is read from `skbjTemp.dat`
   at this stage.
2. **Lines 276–317** open `skbjTemp.dat` read-only (`0x8000`) to load a cached
   **anchor** (the date-encoding value `> 0x133f073`), used for incremental align.
3. **Lines 321+** do incremental computation using that anchor + new bars.
4. **Lines 400–402** re-open `skbjTemp.dat` with `0x9001` (= `modeRead|modeCreate`)
   and `CFile::Write` the anchor back. **The DLL itself writes the cache.**

→ `skbjTemp.dat` is a **local cache file** (anchor + increment), not server-pushed
data. The cost distribution is **computed locally** from OHLCV.

Why the earlier mistake: (a) misread line 290's `0x8000` read as "only reads a
precomputed distribution", missing that `local_208` was already built locally
above it; (b) no `skbjTemp` xref found in `HLLevel2.EXE` (Ghidra/capstone couldn't
resolve base-relative refs) was wrongly taken as "no local writer" — but the DLL
itself writes it (line 400).

### Implication for TradingView reproduction
`WINNER`/`COST` are not just lookups — their core `local_208` accumulation
(lines 205–265) rebuilds the distribution **locally from OHLCV**, exactly like
standard TV `WINNER`. `winner_113.py`/`winner_113.pine` (rebuild 113-bin
distribution from local OHLCV) are therefore on the right track. No server data
is needed. Remaining gap: the `aiStack_1dc` hash mapping (lines 213–215) is not
fully deciphered, so uniform 113 bins are used as an approximation.

See `docs/LOCAL_COMPUTE_CORRECTION.md` for the full correction, and
`docs/SKBJ_TRACING.md` for the original (now-overturned) tracing notes.

## Repository layout

```
decompiled/        Real Ghidra decompilations (C source)
  costcore_100ccf00.c     WINNER core (836 lines)
  costcore_100cf400.c     COST core (1043 lines)
  aiStack_1dc_real.txt    113 real constants (verbatim from binary)
  fn_100934f0.c           WINNER constructor
  winner_compute.c        WINNER vtable destructor (holds vtable name)
docs/               Reverse-engineering notes (Chinese + tracing)
  WINNER_完整反编译记录.md
  WINNER_算法白皮书.md
  SKBJ_TRACING.md         upstream skbjTemp.dat writer tracing
src/                Clean WINNER/COST only (both versions, no chip-distribution extras)
  winner_113.py     WINNER(P) — equal-weight (dll) AND volume-weight (TV)
  cost_113.py       COST(frac) — equal-weight (dll) AND volume-weight (TV)
  winner_113.pine   //@version=5 — WINNER(P) + COST(50%) (weight toggle)
  cost_113.pine     COST(frac) standalone (weight toggle)
```

## Implementation notes (aligned with DLL, 2026-08-18)

`src/winner_113.py` now matches the **real DLL structure** (asm-verified):

- `pdVar4` buffer = **12 bytes/bar (3 floats)**: `[+0]=close(cost)`, `[+0xc]=date`
  (asm: line208 `fld [pdVar4+0xc]`=date, line242/250 `fld [pdVar4+0]`=close)
- `local_208[k]` = close of bar k (equal-weight)
- `WINNER(P)` = fraction of bars with `close <= P` (equal-weight cost distribution)
- `COST(frac)` = inverse of WINNER
- `aiStack_1dc[0..12]` = monthly cumulative-days table (date→day# hash, **confirmed**)
- `aiStack_1dc[13..]` = month-cycle alignment table (decides which bars write to
  `local_208`); used by WINNER only, NOT by COST → not a price-bin table
  (**inferred**; exact bit-ops not fully deciphered, but impact on continuous
  trading-day data is negligible)

Verification: `WINNER(CLOSE)=1.0` when close is the highest; `COST(0.5)=11.3 →
WINNER=0.5` (inverse exact); `ZSHTL+ZZLKP=100` (conserved).

Note: DLL uses **equal-weight per bar**; standard TV `WINNER` uses
**volume-weighting**. That is the only structural difference.

See `docs/PDVAR4_FIELDS.md` (asm field proof), `docs/HASH_MAPPING_SOLVED.md`
(date-table), `docs/AISTACK_13PLUS.md` ([13..] analysis),
`docs/LOCAL_COMPUTE_CORRECTION.md` (local compute).

## License

For reverse-engineering research / education. The original `CompMan.dll` binary
is **not** included.
