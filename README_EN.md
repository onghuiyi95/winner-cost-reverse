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
| `FUN_100ccf00` | WINNER core | 836-line decompile — reads `skbjTemp.dat`, double-loop accumulates `local_208` (volume per bin), WINNER lookup (line 405–431) |
| `FUN_100cf400` | COST core | 1043-line decompile — inverse of WINNER: finds the price where cumulative volume ratio ≥ `frac` |
| `FUN_100934f0` | WINNER ctor | sets 14 flags by type code `0x138`, vtable `PTR_WINNER_IMPL_1015e7f8` |
| `aiStack_1dc[113]` | lookup table | 113 real constants extracted verbatim (see `decompiled/aiStack_1dc_real.txt`) |

Both functions are **isomorphic**: each does data-load (`FUN_100dd8dc` /
`FUN_1009e2d0`) + math (double-loop accumulation) + thread-locks
(`LOCK`/`UNLOCK`) + result formatting (`%.3lf`). They are **not** a "one does
infra, one does math" split.

## Key result: who computes the chip distribution? (skbjTemp.dat tracing)

`skbjTemp.dat` is referenced **read-only once** in the whole `CompMan.dll`
(`CFile::Open(..., 0x8000 = modeRead)`, then `CFile::Read`/`Close`). A full
scan shows **zero** `modeWrite`/`modeCreate` and **only one** `.dat` filename.
→ The chip-distribution data is **pre-computed and written to disk by HongLiTong's
upstream data engine** (separate process / likely server-pushed daily
distribution). `WINNER`/`COST` only **read the cache and do a table lookup** —
they do **not** compute the raw cost distribution.

### Upstream-writer tracing (2026-08-18)

Scanned `HLLevel2.EXE`, `HLLevel2-2.EXE`, `Fortune.EXE`, `RecvSend-*.dll`, `CompMan.dll`:

| Binary | skbjTemp string | References it (write)? |
|---|---|---|
| `CompMan.dll` | yes | read-only (`modeRead`) |
| `HLLevel2.EXE` | yes (VA `0x00d137c1`, `.rdata`) | **no static xref** (base-relative ref, Ghidra/capstone can't resolve) |
| `HLLevel2-2.EXE` | yes | same copy |
| `Fortune.EXE` | **no** | — |
| `RecvSend-*.dll` | **no** | — |

`HLLevel2.EXE` **does** have `modeWrite` file I/O, but capstone shows those
writer functions write **raw market data**, not chip distribution:
`1A0001` `tick` `real` `stockinfo` `trend` `%s%s-%s.%hx` `%04d%02d%02d`
(date + hex-suffix filenames = raw tick/day feeds), plus `hqServer.exe`
`Zm_rece.exe` (quote server / receiver). `skbjTemp` is **not** among them.

**Conclusion:** `skbjTemp.dat` is **not written by any locally-analyzable
binary** — it is **computed by the HongLiTong quote server and pushed down**;
the client receives it and persists it as a cache, then `WINNER`/`COST` read it.
The raw cost-distribution algorithm lives **server-side**, not in this DLL.

→ Reproducing on TradingView: `WINNER`/`COST` are easy (lookups); the hard part
is rebuilding the `skbjTemp.dat` distribution, which requires either capturing
the server protocol or approximating with standard TV `WINNER` from local OHLCV.

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
src/                Implementations (verified)
  winner_113.py     WINNER(P) + main-chip distribution (ZLCM/SHCM/ZSHTL/ZZLKP)
  cost_113.py       COST(frac) + WINNER↔COST inverse check
  winner_113.pine   //@version=5 — WINNER + COST + chips (single runnable file)
  cost_113.pine     COST standalone
```

## Implementation notes

The implementation replicates the DLL's two-layer structure: build a 113-bin
volume-accumulation array (aligned with `local_208`), then `WINNER(P)` =
cumulative ratio up to the target bin (aligned with line 405–431), and
`COST(frac)` = inverse lookup (aligned with `FUN_100cf400`).

Verification: `ZSHTL + ZZLKP = 100` (conserved); `COST(0.5)=106.4 → WINNER=0.5015`.

`aiStack_1dc[113]` is included verbatim but its exact hash-mapping
(price→bin, lines 205–265) is **not fully deciphered** — the implementation
uses uniform 113 bins to replicate the accumulate+lookup structure. The upstream
`skbjTemp.dat` algorithm is **outside this DLL** (see above).

## License

For reverse-engineering research / education. The original `CompMan.dll` binary
is **not** included.
