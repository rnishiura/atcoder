from math import sqrt
N = int(input())

A = []
max_val = 0
for i in range(N):
  b = tuple(map(int, input().split()))
  for a in A:
    max_val = max(max_val, (a[0]-b[0])**2+(a[1]-b[1])**2)
  A.append(b)

print(sqrt(max_val))