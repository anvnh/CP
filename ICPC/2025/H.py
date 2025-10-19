n = int(input())
a = list(map(int, input().split()))

d0 = 0
d = 0
m = -float("inf")
md = float("inf")

for i in a:
      if(i == 0):
            d0 += 1
      if(i < 0):
            m = max(m, i)
            d += 1
      if(i > 0):
            md = min(md, i)

# print(d0, d,  m)

if(d0 >= 2):
      print(max(a), min(a))
elif(d0 == 1 and d % 2 == 0):
      print(0, 0)
elif(d0 == 1 and d % 2 == 1):
      if(d0 + d == n):
            print(m, min(a))
      else:
            print(max(a), min(a))

elif(d0 == 0 and d % 2 == 1):
      print(m, m)
elif(d0 == 0 and d % 2 == 0):
      if(md == float("inf")):
            print(min(a), min(a))
      else:
            print(md, md)




