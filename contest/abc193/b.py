N = int(input())

flg = False
min_price = 1000000000


for i in range(N):
  A, P, X = tuple(map(int, input().split()))
  if X-A > 0:
    flg = True
    min_price = min(P, min_price)

if flg:
  print(min_price)
else:
  print(-1)