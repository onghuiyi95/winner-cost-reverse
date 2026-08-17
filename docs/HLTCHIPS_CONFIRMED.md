# 弘历 dll 筹码分布函数确认 (2026-08-18)

## 用户发现: HLLevel2-3.EXE 里有"成本分布"
字符串扫描 HLLevel2-3.EXE (15MB):
- "成本分布" 出现 7 次 (菜单"添加成本分布", "输入数值N表示N天前(后)成本分布")
- "筹码" 3次, "HLTCHIPS" 1次, "HLTHLP" 5次, "HLTFDP" 4次
- "skbjTemp" 1次: "\\skbjTemp.dat...510050.day" (上证50ETF日线成本缓存)
- 全套 HLT* 函数名 (HLTCHIPS/HLTHLP/HLTFDP/HLTWINNER/HLTCH...)

## dll 反编译确认 HLTCHIPS/HLTHLP/HLTWINNER/COST 都是成本分布家族
xref HLTCHIPS串(VA 0x1015ea8c) -> 引用者 = FUN_10097610 (公式派发器)
同被 FUN_10097610 引用的名字串: HLTCHIPS, HLTHLP, HLTWINNER, COST
(四个 .c 文件内容完全相同 = 都是 FUN_10097610 函数体, 从各自 xref 入口进入)

### FUN_10097610 是公式注册表 (2665行)
每个公式 = operator_new(0x24) + FUN_100064c0("<名字>") + FUN_100934f0(0xXX)
确认注册项(节选):
  line 968:  FUN_100064c0("WINNER")
  line 1968: FUN_100064c0("HLTWINNER")
  line 1978: FUN_100064c0("HLTHLP")
  line 2132: FUN_100064c0("HLTCHIPS")   <<< 筹码分布函数注册
  + DRAWBAND, LUNARDATE, DAYSEDGE, FILLRGNALPHA, ASI ... 全套公式名

## 结论 (铁证)
HLTCHIPS = 弘历公式系统的"筹码分布"函数, 与 WINNER/HLTWINNER/HLTHLP/COST
同属一个注册体系 -> 底层走同一套成本分布算法
(FUN_100ccf00 WINNER 836行 + FUN_100cf400 COST 1043行, 已反编译)

弘历的 HLTCHIPS/HLTHLP/HLTFDP = 通达信 CYQ 的同源功能
(价格->持仓占比, 获利/套牢分色, 本地运算)

## 与用户截图对应
- 通达信教学图(筹码分布01.png) -> CYQ
- 通达信浦发银行火焰山(cbfb.PNG) -> CYQ 真实渲染(获利93.88%/套牢6.12%, 成本分布日期20210312)
- 弘历 HLTCHIPS/HLTHLP/HLTFDP -> 弘历版 CYQ
- winner_113.py(等权/加权) -> 算法可运行复现
