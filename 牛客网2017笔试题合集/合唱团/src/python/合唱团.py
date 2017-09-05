#-*- coding:utf-8 -*-
n = int(raw_input())
arr = map(int,raw_input().split())
K,D = map(int,raw_input().split())
 
fm = [ ([0]*n) for i in range(K) ] # k*d
fn = [ ([0]*n) for i in range(K) ] # k*d
res=0
#fm,fn表示 能力值的最大值和最小值，因为有正有负
#fm[k][i]表示从n个人中选取k+1个人时最大的能力值，i表示第k个人的位置
for i in range(n):
    fm[0][i]=arr[i]
    fn[0][i]=arr[i]
    
for i in range(n):
    for k in range(1,K):
        for j in range(i-1,max(0,i-D)-1,-1):
            #之所以要max(fm[k][i],是要取本组循环中最大/小的值
                fm[k][i] = max(fm[k][i],max(fm[k-1][j]*arr[i], fn[k-1][j]*arr[i]))
                fn[k][i] = min(fn[k][i],min(fm[k-1][j]*arr[i], fn[k-1][j]*arr[i]))
    res=max(res,fm[K-1][i])
print res