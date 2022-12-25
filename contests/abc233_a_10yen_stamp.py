from math import ceil
X, Y = tuple(map(int, input().split()))

if X >= Y:
  print(0)
else:
  print((Y-1-X)//10+1)
