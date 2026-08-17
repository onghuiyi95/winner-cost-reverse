# -*- coding: utf-8 -*-
"""
火焰山(成本分布/CYQ) 绘制 — 版本A: Python matplotlib
算法对齐弘历 dll FUN_008d9950 (逆向铁证):
  - 每根K线 1000 价格桶的成交量加权直方图
  - 获利盘 = 截止价以下桶累计 / 总累计
  - N天前% = 直方图往前回溯 N 根K线再算获利盘
  - 常量: 价格精度10000.0, 百分比100.0
布局: 左K线 + 右火焰山(横轴占比/纵轴价格, 黄=获利红=套牢) + 右下数据表
"""
import csv, datetime
import numpy as np
import matplotlib
matplotlib.use("Agg")
import matplotlib.pyplot as plt
plt.rcParams["font.sans-serif"]=["SimHei","Microsoft YaHei","SimSun"]
plt.rcParams["axes.unicode_minus"]=False

CSV = r"C:/Users/Administrator/hllevel2_reverse/winner_reverse/pufa_600000.csv"
CUT_DATE = 20210312   # 成本分布日期 (你截图)
NBINS = 1000          # dll: 每根K线1000价格桶
LOOKBACKS = [100,90,80,70,60,50,40,30,20,10]  # 你图里的 N天前

def load(csv_path, cut=None):
    bars=[]
    with open(csv_path) as f:
        for r in csv.DictReader(f):
            d=int(r["date"])
            if cut and d>cut: continue
            bars.append((int(d),float(r["open"]),float(r["high"]),float(r["low"]),float(r["close"]),float(r["vol"])))
    return bars

def cost_histogram(bars, nbins=NBINS):
    closes=[b[4] for b in bars]; vols=[b[5] for b in bars]
    lo=min(closes); hi=max(closes)
    edges=np.linspace(lo,hi,nbins+1); centers=(edges[:-1]+edges[1:])/2
    hist=np.zeros(nbins)
    for c,v in zip(closes,vols):
        idx=int((c-lo)/(hi-lo)*(nbins-1)); idx=max(0,min(nbins-1,idx)); hist[idx]+=v
    return centers, hist, lo, hi

def winner_at(hist, centers, price):
    tot=hist.sum()
    if tot<=0: return 0.0
    idx=int((price-centers[0])/(centers[-1]-centers[0])*(len(centers)-1)) if centers[-1]>centers[0] else 0
    idx=max(0,min(len(hist)-1,idx))
    return hist[:idx+1].sum()/tot

def compute(bars, cut_date=CUT_DATE, lookbacks=LOOKBACKS):
    idx_cut=None
    for i,b in enumerate(bars):
        if b[0]>=cut_date: idx_cut=i; break
    if idx_cut is None: idx_cut=len(bars)-1
    sub=bars[:idx_cut+1]; cur_price=sub[-1][4]
    centers,hist,lo,hi=cost_histogram(sub)
    win_now=winner_at(hist,centers,cur_price)
    rows=[]
    for n in lookbacks:
        k=max(1,idx_cut+1-n)
        c2,h2,_,_=cost_histogram(bars[:k+1])
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
    ax.set_xlabel("持仓占比 (%)"); ax.set_ylabel("价格"); ax.set_title("火焰山成本分布 浦发银行600000")
    ax.legend(loc="upper right")
    ax2=fig.add_axes([0.85,0.1,0.14,0.8]); ax2.axis("off")
    txt=["流通盘：-","套牢盘：%.2f%%"%res["loss"],"获利盘：%.2f%%"%res["profit"],
         "成本分布日期：%d"%res["cut_date"]]
    for n,p in res["rows"]: txt.append("%d天前 %.2f%%"%(n,p))
    ax2.text(0,1,"\n".join(txt),fontsize=9,va="top",ha="left")
    plt.savefig(out_png,dpi=110,bbox_inches="tight"); print("A版图 ->", out_png)

if __name__=="__main__":
    bars=load(CSV, cut=CUT_DATE); res=compute(bars)
    print("当前价 %.2f  获利盘 %.2f%%  套牢盘 %.2f%%"%(res["cur_price"],res["profit"],res["loss"]))
    for n,p in res["rows"]: print("%d天前 %.2f%%"%(n,p))
    draw_a(res, r"C:/Users/Administrator/hllevel2_reverse/winner_reverse/flame_A.png")
