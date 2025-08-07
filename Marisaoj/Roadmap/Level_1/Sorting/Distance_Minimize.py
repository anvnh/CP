n = int(input())
points = []
for _ in range(n):
    x, y = map(int, input().strip().split())
    points.append((x, y))
sorted(points)
if(n&1):
    n = n >> 1
else:
    n = (n >> 1) - 1
print(x, y)

