t = int(input())
for _ in range(t):
    n, a, b = map(int, input().split())
    if n <= 3:
        print(min(min(a, b) * n, b))
        continue
    if a <= b:
        if a * 3 >= b:
            print((n // 3) * b + (n % 3) * min(a, b))
        else:
            print(n * a)
    else:
        print((n // 3) * b + (n % 3) * b)
