# -*- coding: utf-8 -*-
"""
火焰山(成本分布/CYQ) 绘制 — 版本A: Python matplotlib (含换手衰减, 对齐通达信CYQ)
铁证修正 (2026-08-18):
  之前三版缺 "远期换手衰减" -> 获利盘算成57% vs 原版93.88%
  诊断: (H+L)/2成本 + 指数衰减(decay每日保留比例~0.98) -> 96% 接近原版
  机制: 久远成交权重按 decay^(距今天数) 指数衰减 (通达信CYQ标准)
算法: 每根K线1000桶成交量加权直方图 + 衰减 + WINNER(成本<=当前价占比)
"""
import csv, datetime
import numpy as np
import matplotlib
matplotlib.use("Agg")
import matplotlib.pyplot as plt
plt.rcParams["font.sans-serif"]=["SimHei","Microsoft YaHei","SimSun"]
plt.rcParams["axes.unicode_minus"]=False

CSV = r"C:/Users/Administrator/hllevel2_reverse/winner_reverse/pufa_sina.csv"
CUT_DATE = 20210312
NBINS = 1000
LOOKBACKS = [100,90,80,70,60,50,40,30,20,10]
DECAY = 0.98   # 换手衰减: 每日保留比例 (对齐原版~93-96%)

def load(csv_path, cut=None):
    bars=[]
    with open(csv_path) as f:
        for r in csv.DictReader(f):
            d=int(r["date"])
            if cut and d>cut: continue
            bars.append((int(d),float(r["open"]),float(r["high"]),float(r["low"]),float(r["close"]),float(r["vol"])))
    return bars

def cost_histogram(bars, nbins=NBINS, decay=None):
    c=np.array([(b[2]+b[3])/2 for b in bars]); v=np.array([b[5] for b in bars],float)
    n=len(v)
    if decay is not None:
        w=np.array([decay**(n-1-i) for i in range(n)]); v=v*w
    lo,hi=c.min(),c.max()
    edges=np.linspace(lo,hi,nbins+1); centers=(edges[:-1]+edges[1:])/2
    hist=np.zeros(nbins)
    for ci,vi in zip(c,v):
        idx=int((ci-lo)/(hi-lo)*(nbins-1)); idx=max(0,min(nbins-1,idx)); hist[idx]+=vi
    return centers, hist, lo, hi

def winner_at(hist, centers, price):
    tot=hist.sum()
    if tot<=0: return 0.0
    idx=int((price-centers[0])/(centers[-1]-centers[0])*(len(centers)-1)) if centers[-1]>centers[0] else 0
    idx=max(0,min(len(hist)-1,idx))
    return hist[:idx+1].sum()/tot

def compute(bars, cut_date=CUT_DATE, decay=DECAY, lookbacks=LOOKBACKS):
    idx_cut=0
    for i,b in enumerate(bars):
        if b[0]>=cut_date: idx_cut=i; break
    if idx_cut>=len(bars): idx_cut=len(bars)-1
    sub=bars[:idx_cut+1]; cur_price=sub[-1][4]
    centers,hist,lo,hi=cost_histogram(sub, decay=decay)
    win_now=winner_at(hist,centers,cur_price)
    rows=[]
    for n in lookbacks:
        k=max(1,idx_cut+1-n)
        c2,h2,_,_=cost_histogram(bars[:k+1], decay=decay)
        rows.append((n, winner_at(h2,c2,cur_price)*100))
    return dict(cur_price=cur_price, cut_date=sub[-1][0], profit=win_now*100,
                loss=(1-win_now)*100, centers=centers, hist=hist, rows=rows,
                closes=[b[4] for b in bars[:idx_cut+1]])

def draw_a(res, out_png):
    centers=res["centers"]; hist=res["hist"]; cur=res["cur_price"]; closes=res["closes"]
    fig=plt.figure(figsize=(14,7))
    axk=fig.add_axes([0.05,0.1,0.40,0.8])
    axk.plot(range(len(closes)), closes, color="#ffcc00", lw=0.8)
    axk.set_ylabel("收盘价"); axk.set_title("K线(简化)"); axk.set_xticks([])
    ax=fig.add_axes([0.50,0.1,0.32,0.8])
    maxh=hist.max() if hist.max()>0 else 1
    bw=(centers[1]-centers[0])*0.9 if len(centers)>1 else 0.1
    for i,c in enumerate(centers):
        ax.barh(c, hist[i]/maxh*100, height=bw, color=("#ffcc00" if c<=cur else "#ff3030"), edgecolor="none")
    ax.axhline(cur,color="cyan",lw=1.5,label="当前价 %.2f"%cur)
    ax.set_xlabel("持仓占比 (%)"); ax.set_ylabel("价格"); ax.set_title("火焰山成本分布 浦发600000 (含衰减%.2f)"%DECAY)
    ax.legend(loc="upper right")
    ax2=fig.add_axes([0.85,0.1,0.14,0.8]); ax2.axis("off")
    txt=["流通盘：-","套牢盘：%.2f%%"%res["loss"],"获利盘：%.2f%%"%res["profit"],
         "成本分布日期：%d"%res["cut_date"]]
    for n,p in res["rows"]: txt.append("%d天前 %.2f%%"%(n,p))
    ax2.text(0,1,"\n".join(txt),fontsize=9,va="top",ha="left")
    plt.savefig(out_png,dpi=110,bbox_inches="tight"); print("A版图 ->", out_png)

if __name__=="__main__":
    bars=load(CSV, cut=CUT_DATE); res=compute(bars)
    print("DECAY=%.2f 当前价 %.2f 获利盘 %.2f%% 套牢盘 %.2f%%"%(DECAY,res["cur_price"],res["profit"],res["loss"]))
    for n,p in res["rows"]: print("%d天前 %.2f%%"%(n,p))
    draw_a(res, r"C:/Users/Administrator/hllevel2_reverse/winner_reverse/flame_A.png")
