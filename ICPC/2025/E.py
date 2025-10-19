import math
for _ in range(int(input())):
    n=int(input())
    a=list(map(int,input().split()))
    kq=len(a)//2
    d=0
    for i in range(1,len(a),2):
        if not(math.gcd(a[i],a[i-1])==1 or a[i]%a[i-1]==0 or a[i-1]%a[i]==0):
            kq+=1
            d+=1
    if len(a)%2==1:
        d+=1
    if d%2==0:
        kq+=d//2
    else:
        kq+=d//2+2
    print(kq)
