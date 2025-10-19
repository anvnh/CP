import math

for _ in range(int(input())):
    l,r=map(int,input().split())
    x=(r//3-(l-1)//3)
    if l<10:
        x-=1
    if l<4:
        x-=1
    print(x)
