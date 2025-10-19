from collections import deque
import sys
sys.setrecursionlimit(100000)

R,C=map(int,input().split())
a=[]
check=[]
x,y=0,0
ss=[]
for i in range(R):

    t=list(input())
    check.append([0]*C)
    a.append(t)
    for j in range(len(t)):
        if a[i][j]=='S':
            ss.append([i,j])
d=0
q=deque()
for i in ss:
    check[i[0]][i[1]]=1
hp=3
xx=check.copy()

def bfs(x,y,d,hp,c):
    if x-1>=0:
        if c[x-1][y]==0:
            tam=c.copy()
            tam[x-1][y]=1
            if a[x-1][y]=='+' and hp>1:
                q.append([x-1,y,d,hp-1,tam])
            elif a[x-1][y]=='-':
                q.append([x-1,y,d,hp,tam])
            elif a[x-1][y]=="D":
                return(d)
    if x<R-1:
        if c[x+1][y]==0:
            tam=c.copy()
            tam[x+1][y]=1
            if a[x+1][y]=='+' and hp>1:
                q.append([x+1,y,d,hp-1,tam])
            elif a[x+1][y]=='-':
                q.append([x+1,y,d,hp,tam])
            elif a[x+1][y]=="D":
                return(d)
    if y-1>=0:
        if c[x][y-1]==0:
            tam=c.copy()
            tam[x][y-1]=1
            if a[x][y-1]=='+' and hp>1:
                q.append([x,y-1,d,hp-1,tam])
            elif a[x][y-1]=='-':
                q.append([x,y-1,d,hp,tam])
            elif a[x][y-1]=="D":
                return(d)
    if y<C-1:
        if c[x][y+1]==0:
            tam=c.copy()
            tam[x][y+1]=1
            if a[x][y+1]=='+' and hp>1:
                q.append([x,y+1,d,hp-1,tam])
            elif a[x][y+1]=='-':
                q.append([x,y+1,d,hp,tam])
            elif a[x][y+1]=="D":
                return(d)
    if q:
        t=q.popleft()
    else:
        return -2
    return(bfs(t[0],t[1],t[2]+1,t[3],t[4]))
kq=999999999
for i in ss:
    x=i[0]
    y=i[1]
    c=[[0 for i in range(C)] for j in range(R)]

    ta=bfs(x,y,d,hp,c)+1
    if ta!=-1:
        kq=min(kq,ta)
if kq==999999999:
    print(-1)
else:
    print(kq)
