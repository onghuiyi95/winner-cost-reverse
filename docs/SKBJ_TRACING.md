# skbjTemp.dat 上游写入模块 — 追踪结果与最终结论

## 追踪过程 (2026-08-18)

### 1. 定位含 skbjTemp 串的二进制
用 pefile 扫描同目录 + attachments：
- `CompMan.dll`        — 只读引用 (FUN_100ccf00 line 276, modeRead 0x8000) — 客户端
- `HLLevel2.EXE`       — 含串 (VA 0x00d137c1, .rdata 段)
- `HLLevel2-2.EXE`     — 同上副本
- `Fortune.EXE` (主程序) — **不含** skbjTemp 串
- `RecvSend-*.dll`      — **不含** skbjTemp 串
- 全盘搜 `skbjTemp.dat` 文件本体 → **不存在** (运行时按日期生成)

### 2. 尝试 Ghidra 找 skbjTemp xref — 失败
- EXE 非加壳 (标准节名/18导入表/无UPX)
- 但 Ghidra getDefinedData 迭代器识别不出这些串 (auto-analysis 未覆盖)
- getReferencesTo(0x00d137c1) = 0 xref
- capstone 搜绝对地址 `imm==0x00d137c1` = 0, 搜内存 disp 在 0x137xx = 0
→ skbjTemp 在 EXE 里**无静态可追踪的 xref** (基址相关引用或被间接调用)

### 3. 反汇编 EXE 写文件函数 (capstone) — 关键证据
EXE 含 modeWrite/modeCreate 写操作 (15个函数)。反编译这些写函数引用的 .rdata 串：
- `0x00461c7d` / `0x004627b9`: 引用 `1A0001` `1600` `broker` `cdp` `tick` `real` `stockinfo` `trend` `bourseinfo` `%s%s-%s.%hx` `%04d%02d%02d`
  → 这是**原始行情数据落地** (tick/real/day 格式 `%s%s-%s.%hx`, 日期 `%04d%02d%02d`)
- `0x0046414f`: 引用 `hqServer.exe` `Zm_rece.exe` (行情服务器/接收程序)
- `0x004841af`: 引用 `HappyStar.ini` `sjfwq.rzfwq.com` `Union.exp` (更新/公式)

**skbjTemp 不在这批写文件函数里** → EXE 写的是原始行情文件, 不是筹码分布缓存。

## 最终结论

**`skbjTemp.dat` (筹码分布缓存) 不是本机任何可分析二进制写入的。**
它是**弘历行情服务端计算并下发的**:
1. 服务端算好每日/每股票的成本分布数组
2. 客户端 (HLLevel2.EXE) 接收后落地成 `skbjTemp.dat` 系列缓存文件
3. WINNER/COST (CompMan.dll) 只 `modeRead` 读取 + 查表

佐证:
- CompMan.dll 对 skbjTemp 仅 modeRead, 零写入
- HLLevel2.EXE 含串但无写函数引用, 且实际写的是 tick/real/day 原始行情
- Fortune.EXE / RecvSend 完全不含串
- skbjTemp.dat 本机不存在 (运行时由接收的数据生成)
- `%s%s-%s.%hx` 文件名格式暗示 EXE 写的是带 hex 后缀的行情文件, 与 skbjTemp 形态不同

## 对逆向的意义

要在 TradingView 复现 WINNER/COST:
- WINNER/COST 本身 = 查表 (已反编译, 易复现)
- 真正难点 = 重建 skbjTemp.dat 背后的**成本分布算法**
- 该算法在**服务端**, 不在本机任何二进制 → 需要:
  (a) 抓包弘历行情协议, 看服务端下发的筹码分布数据格式, 或
  (b) 用 TV 标准 WINNER 算法 (基于本地 OHLCV 重建成本分布) 近似

## 文件
- `scan_skbj_dlls.py` — 扫描同目录含 skbjTemp 串
- `capstone_writers.py` / `capstone_writers2.py` — EXE 写文件函数分析
- `capstone_filemodes.py` — 文件模式常量定位
- `bin_search_skbj.py` / `calc_skbj_va.py` — skbjTemp VA 计算
- `_find_skbj_writer*.py` — Ghidra xref 尝试 (因 EXE 字符串未识别失败)
