import sys,numpy as np
def mincost(li,i,j,n,m):
    if i>=n or j>=m:
        return sys.maxsize
    if i==n-1 and j==m-1:
        return li[i][j]
    
    ans1=mincost(li,i,j+1,n,m)
    ans2=mincost(li,i+1,j,n,m)
    ans3=mincost(li,i+1,j+1,n,m)
    
    ans=li[i][j]+min(ans1,ans2,ans3)
    return ans










li=[]
cost=input().strip().split()
n=int(cost[0])
m=int(cost[1])
for i in range(n):
    row=[int(elem) for elem in list(input().strip().split())]
    li.append(row)
    
print(mincost(li,0,0,n,m))
