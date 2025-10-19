n=int(input())
a=list(map(int,input().split()))
print(abs(sum(a[:n//2])-sum(a[n//2:])))
