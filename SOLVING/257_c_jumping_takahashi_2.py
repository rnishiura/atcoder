N = int(input())
A = []
B = []
import math

for i in range(N):
  A.append(list(map(int, input().split())))

for a in A:
  s = 10e9+1
  for b in A:
    if a == b:
      continue
    s = min(s, (abs(b[0]-a[0]) + abs(b[1]-a[1]) ) / max(b[2], a[2]))
  B.append(s)

print(math.ceil(max(B)))

