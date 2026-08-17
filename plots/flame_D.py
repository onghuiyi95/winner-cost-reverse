# -*- coding: utf-8 -*-
"""
火焰山绘制 — 版本D: 复刻 Quantum Terminal Pro (app.js) CYQ 算法
对齐源码: lookback=150滚动窗口 / (H+L+C)/3成本 / 0.96^daysAgo衰减 / 80桶
同时支持全历史模式 (对齐通达信/用户原图93.88%: decay~0.99)
"""
import csv, numpy as np
import matplotlib; matplotlib.use("Agg")
import matplotlib.pyplot as plt
plt.rcParams["font.sans-serif"]=["SimHei","Microsoft YaHei","SimSun"]
plt.rcParams["axes.unicode_minus"]=False

CSV = r"C:/Users/Administrator/hllevel2_reverse/winner_reverse/pufa_sina.csv"
CUT_DATE = 20210312
LOOKBACK = 150     # app默认滚动窗口; None=全历史(对齐原图)
NUM_BUCKETS = 80
DECAY = 0.96       # app默认; 全历史模式用0.99对齐原图

def load(path):
    rows=[]
    with open(path) as f:
        for r in csv.DictReader(f):
            rows.append((int(r["date"]),float(r["open"]),float(r["high"]),float(r["low"]),float(r["close"]),float(r["vol"])))
    return rows

def cyq(bars, ti, lookback=LOOKBACK, nb=NUM_BUCKETS, decay=DECAY):
    start=0 if lookback is None else max(0,ti-lookback)
    window=bars[start:ti+1]
    if not window: return None
    cur=bars[ti][4]
    minP=min(k[3] for k in window); maxP=max(k[2] for k in window)
    if minP==maxP: return None
    bs=(maxP-minP)/nb
    buckets=np.zeros(nb); total=0.0; n=len(window)
    for i,k in enumerate(window):
        avg=(k[2]+k[3]+k[4])/3
        bidx=max(0,min(nb-1,int((avg-minP)/bs)))
        w=decay**(n-1-i); adj=(k[5] or 1)*w
        buckets[bidx]+=adj; total+=adj
    centers=minP+np.arange(nb)*bs+bs/2
    profit=buckets[centers<=cur].sum()
    profitPct=profit/total*100 if total>0 else 0
    avgCost=(centers*buckets).sum()/total if total>0 else cur
    return dict(cur=cur, profit=profitPct, loss=100-profitPct, avgCost=avgCost,
                centers=centers, buckets=buckets, total=total, minP=minP, maxP=maxP, n=n)

def draw_d(res, out_png, title_suffix=""):
    fig,ax=plt.subplots(figsize=(7,8))
    maxb=res["buckets"].max() if res["buckets"].max()>0 else 1
    bw=(res["centers"][1]-res["centers"][0])*0.9
    for i,c in enumerate(res["centers"]):
        h=res["buckets"][i]/maxb*100
        if h<=0: continue
        # app配色: 获利(<=当前价)红, 套牢绿
        col="#f23645" if c<=res["cur"] else "#089981"
        ax.add_patch(plt.Rectangle((0,c-bw/2), h, bw, color=col, edgecolor="none"))
    ax.axhline(res["cur"],color="cyan",lw=1.5,label="当前价 %.2f"%res["cur"])
    ax.set_xlim(0,105); ax.set_ylim(res["minP"],res["maxP"])
    ax.set_xlabel("持仓占比 (%)"); ax.set_ylabel("价格")
    ax.set_title("CYQ(复刻Quantum app%s)\n获利%.2f%% 套牢%.2f%% 均成%.2f"%(title_suffix,res["profit"],res["loss"],res["avgCost"]))
    ax.legend(loc="upper right")
    txt=["获利盘：%.2f%%"%res["profit"],"套牢盘：%.2f%%"%res["loss"],
         "平均成本：%.2f"%res["avgCost"],"窗口：%d根"%res["n"]]
    ax.text(1.02,0.5,"\n".join(txt),fontsize=9,va="center",ha="left",transform=ax.transAxes)
    plt.savefig(out_png,dpi=110,bbox_inches="tight"); print("D版(Quantum复刻) ->", out_png)

if __name__=="__main__":
    rows=load(CSV)
    idx=None
    for i,b in enumerate(rows):
        if b[0]>=CUT_DATE: idx=i; break
    if idx is None: idx=len(rows)-1
    # 1) app默认 (150窗口, decay0.96)
    r1=cyq(rows, idx, lookback=150, decay=0.96)
    print("[app默认 150窗口 decay0.96] 末收%.2f: 获利%.2f%% 套牢%.2f%%"%(r1["cur"],r1["profit"],r1["loss"]))
    draw_d(r1, r"C:/Users/Administrator/hllevel2_reverse/winner_reverse/flame_D_app.png", " 默认")
    # 2) 全历史 (对齐原图 decay0.99)
    r2=cyq(rows, idx, lookback=None, decay=0.99)
    print("[全历史 decay0.99] 末收%.2f: 获利%.2f%% 套牢%.2f%%"%(r2["cur"],r2["profit"],r2["loss"]))
    draw_d(r2, r"C:/Users/Administrator/hllevel2_reverse/winner_reverse/flame_D_full.png", " 全历史0.99")
