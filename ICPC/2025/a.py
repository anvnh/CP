import math
for _ in range(int(input())):
    n,c,d=map(int,input().split())
    a=list(map(int,input().split()))
    b=list(map(int,input().split()))
    x=list(a)
    y=list(b)
    e=[0]*n
    kq1=0
    kq2=0
    ma=max(a)
    for i in range(n):
        if a[i]<ma-c:
            e[i]+=ma-c-a[i]
            kq1+=ma-c-a[i]
            b[i]+=ma-c-a[i]
            a[i]=ma-c
    if max(b)-min(b)>d:
        ma=max(b)
        for i in range(n):
            if b[i]<ma-d:
                kq1+=ma-d-b[i]
                a[i]+=ma-d-b[i]
        if max(a)-min(a)>c:
            kq1=-9999999
    a=list(x)
    b=list(y)
    e=[0]*n
    ma=max(b)
    for i in range(n):
        if b[i]<ma-d:
            e[i]+=ma-d-b[i]
            kq2+=ma-d-b[i]
            a[i]+=ma-d-b[i]
            b[i]=ma-d
    if max(a)-min(a)>c:
        ma=max(a)
        for i in range(n):
            if a[i]<ma-c:
                kq2+=ma-c-a[i]
                b[i]+=ma-c-a[i]
        if max(b)-min(b)>d:
            kq2=-999999
    if kq1<0 and kq2<0:
        print(-1)
    else:
        print(max(kq1,kq2))
