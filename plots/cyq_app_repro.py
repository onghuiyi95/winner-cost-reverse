# -*- coding: utf-8 -*-
"""
复现 Quantum Terminal Pro (app.js) 的 CYQ 筹码分布算法
逐行对齐源码铁证:
  lookback = 150  (截止日前150根滚动窗口)
  numBuckets = 80
  avgPrice = (high+low+close)/3   (当日成本)
  weight = 0.96^daysAgo           (每日保留96%衰减)
  profitVol = 成本<=当前收盘 的桶累计
  获利盘% = profitVol/totalVol*100
分色: 获利(<=当前价)=红, 套牢(>当前价)=绿
"""
import csv, numpy as np

def load(path):
    rows=[]
    with open(path) as f:
        for r in csv.DictReader(f):
            rows.append((int(r["date"]),float(r["open"]),float(r["high"]),float(r["low"]),float(r["close"]),float(r["vol"])))
    return rows

def cyq_app(bars, target_index, lookback=150, numBuckets=80, decay=0.96):
    """对齐 app.js drawCyqCanvas 核心"""
    start=max(0,target_index-lookback)
    window=bars[start:target_index+1]
    if not window: return None
    cur=bars[target_index][4]  # 当前收盘
    minP=min(k[3] for k in window); maxP=max(k[2] for k in window)
    if minP==maxP: return None
    bs=(maxP-minP)/numBuckets
    buckets=np.zeros(numBuckets); total=0.0
    n=len(window)
    for i,k in enumerate(window):
        avg=(k[2]+k[3]+k[4])/3
        bidx=int((avg-minP)/bs); bidx=max(0,min(numBuckets-1,bidx))
        daysAgo=n-1-i
        w=decay**daysAgo
        adj=(k[5] or 1)*w
        buckets[bidx]+=adj; total+=adj
    profit=0.0
    for i in range(numBuckets):
        bPrice=minP+i*bs+bs/2
        if bPrice<=cur: profit+=buckets[i]
    profitPct=profit/total*100 if total>0 else 0
    totalCost=sum((minP+i*bs+bs/2)*buckets[i] for i in range(numBuckets))
    avgCost=totalCost/total if total>0 else cur
    return dict(cur=cur, profit=profitPct, loss=100-profitPct, avgCost=avgCost,
                minP=minP, maxP=maxP, n=n)

def state_app(bars, target_index, lookback=150, numBuckets=80, decay=0.96):
    """对齐 app.js getCyqState"""
    start=max(0,target_index-lookback)
    window=bars[start:target_index+1]
    if not window: return 'YELLOW'
    minP=min(k[3] for k in window); maxP=max(k[2] for k in window)
    if minP==maxP: return 'YELLOW'
    bs=(maxP-minP)/numBuckets
    buckets=np.zeros(numBuckets); total=0.0; n=len(window)
    for i,k in enumerate(window):
        avg=(k[2]+k[3]+k[4])/3
        bidx=int((avg-minP)/bs); bidx=max(0,min(numBuckets-1,bidx))
        w=decay**(n-1-i); adj=(k[5] or 1)*w
        buckets[bidx]+=adj; total+=adj
    pr=maxP-minP
    botLim=minP+pr*0.3; topLim=maxP-pr*0.3
    botV=topV=0.0
    for i in range(numBuckets):
        bp=minP+i*bs+bs/2
        if bp<=botLim: botV+=buckets[i]
        if bp>=topLim: topV+=buckets[i]
    if total>0:
        botPct=botV/total*100; topPct=topV/total*100
        if topPct>=62: return 'RED'
        if botPct>=62: return 'PURPLE'
    return 'YELLOW'

if __name__=="__main__":
    rows=load(r"C:/Users/Administrator/hllevel2_reverse/winner_reverse/pufa_sina.csv")
    print("=== Quantum Terminal Pro CYQ 算法复现 (新浪浦发600000) ===")
    for cut in [20210312, 20210830, 20211027]:
        idx=None
        for i,b in enumerate(rows):
            if b[0]>=cut: idx=i; break
        if idx is None: idx=len(rows)-1
        r=cyq_app(rows, idx)
        st=state_app(rows, idx)
        print(f"\n截止{cut} (idx={idx}, 末收{r['cur']:.2f}, 窗口{r['n']}根):")
        print(f"  获利盘: {r['profit']:.2f}%  套牢盘: {r['loss']:.2f}%  平均成本: {r['avgCost']:.2f}")
        print(f"  状态: {st}  (价格区间 {r['minP']:.2f}~{r['maxP']:.2f})")
