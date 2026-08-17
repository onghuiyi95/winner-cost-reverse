# -*- coding: utf-8 -*-
"""
火焰山绘制 — 版本C: 精确复刻弘历 dll FUN_008f1100 绘制逻辑
对齐 reverse 铁证:
  FUN_008f1100 从 DAT_0113e1cc(价格档数组) / DAT_0113e278(占比数组) 读预算结果
  对每个价格档 iVar13:
    - Draw3dRect(矩形, 颜色) 画横向条形 (高度=占比, 颜色按获利黄/套牢红)
    - TextOut 输出 "%d天前 %.2f%%" (thunk_FUN_00428ed0 格式化 DAT_00f80e90="%d天前%.2f%%")
  颜色来自 param_3+0x16 的颜色表 (套牢/获利分色)
本实现: 用 matplotlib Rectangle 模拟 Draw3dRect, 严格按 dll 的 "读数组->逐档画矩形" 顺序
"""
import csv, datetime
import numpy as np
import matplotlib
matplotlib.use("Agg")
import matplotlib.pyplot as plt
from matplotlib.patches import Rectangle
plt.rcParams["font.sans-serif"]=["SimHei","Microsoft YaHei","SimSun"]
plt.rcParams["axes.unicode_minus"]=False

CSV = r"C:/Users/Administrator/hllevel2_reverse/winner_reverse/pufa_600000.csv"
CUT_DATE = 20210312
NBINS = 1000

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

def compute(bars, cut_date=CUT_DATE, lookbacks=[100,90,80,70,60,50,40,30,20,10]):
    idx_cut=None
    for i,b in enumerate(bars):
        if b[0]>=cut_date: idx_cut=i; break
    if idx_cut is None: idx_cut=len(bars)-1
    sub=bars[:idx_cut+1]; cur=sub[-1][4]
    centers,hist,lo,hi=cost_histogram(sub)
    win_now=winner_at(hist,centers,cur)
    # dll: DAT_0113e1cc=价格档, DAT_0113e278=占比 -> 这里直接构造
    price_bins=centers          # DAT_0113e1cc (价格档)
    pct_bins=hist/hist.sum()*100 # DAT_0113e278 (占比)
    rows=[]
    for n in lookbacks:
        k=max(1,idx_cut+1-n); c2,h2,_,_=cost_histogram(bars[:k+1])
        rows.append((n, winner_at(h2,c2,cur)*100))
    return dict(cur=cur, cut=sub[-1][0], profit=win_now*100, loss=(1-win_now)*100,
                price_bins=price_bins, pct_bins=pct_bins, rows=rows)

def draw_c(res, out_png):
    """复刻 FUN_008f1100: 逐档 Draw3dRect 画横向矩形"""
    fig,ax=plt.subplots(figsize=(9,8))
    # 价格轴 (y) x 占比 (x)
    maxp=res["pct_bins"].max() if res["pct_bins"].max()>0 else 1
    bw=(res["price_bins"][1]-res["price_bins"][0])*0.9
    # dll: 颜色表 param_3+0x16 (套牢红/获利黄)
    for i,c in enumerate(res["price_bins"]):
        h=res["pct_bins"][i]/maxp*100
        if h<=0: continue
        col="#ff3030" if c>res["cur"] else "#ffcc00"  # 套牢红/获利黄 (对齐 dll 分色)
        # Draw3dRect 模拟: 画一个横向矩形 (左=0, 右=h, 中心在价格c)
        ax.add_patch(Rectangle((0, c-bw/2), h, bw, color=col, edgecolor="none"))
    ax.axhline(res["cur"],color="cyan",lw=1.5,label="当前价 %.2f"%res["cur"])
    ax.set_xlim(0,105); ax.set_ylim(res["price_bins"][0], res["price_bins"][-1])
    ax.set_xlabel("持仓占比 (%)"); ax.set_ylabel("价格")
    ax.set_title("火焰山(复刻弘历FUN_008f1100) 浦发银行600000")
    ax.legend(loc="upper right")
    # 右下数据表 (thunk_FUN_00428ed0 输出 "%d天前%.2f%%")
    txt=["流通盘：-","套牢盘：%.2f%%"%res["loss"],"获利盘：%.2f%%"%res["profit"],
         "成本分布日期：%d"%res["cut"]]
    for n,p in res["rows"]: txt.append("%d天前 %.2f%%"%(n,p))
    ax.text(1.02,0.5,"\n".join(txt),fontsize=9,va="center",ha="left",transform=ax.transAxes)
    plt.savefig(out_png,dpi=110,bbox_inches="tight"); print("C版图(复刻dll) ->", out_png)

if __name__=="__main__":
    bars=load(CSV, cut=CUT_DATE); res=compute(bars)
    print("当前价 %.2f 获利盘 %.2f%% 套牢盘 %.2f%%"%(res["cur"],res["profit"],res["loss"]))
    for n,p in res["rows"]: print("%d天前 %.2f%%"%(n,p))
    draw_c(res, r"C:/Users/Administrator/hllevel2_reverse/winner_reverse/flame_C.png")
