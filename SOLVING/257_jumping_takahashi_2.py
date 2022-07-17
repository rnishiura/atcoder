from math import inf
from numpy import ceil

N = int(input())
A = [tuple(map(int, input().split())) for i in range(N)]

# print(A)

# calc incoming cost for all loc
IC = [inf for i in range(N)]
OC = [inf for i in range(N)]
i = 0
for xi, yi, pi in A:
  for xj, yj, pj in A:
    if (xi, yi) == (xj, yj):
      continue
    IC[i] = min(IC[i], (abs(xi-xj)+abs(yi-yj))/pj)
    OC[i] = min(OC[i], (abs(xi-xj)+abs(yi-yj))/pi)
  i += 1
# OC.sort(key=lambda x:)
# IC.sort()
B = sorted(zip(IC, OC), reverse=True)
for i in range(N):
  IC[i] = B[i][0]
  OC[i] = B[i][1]

for i in range(N):
  if B[i][0]>B[i][1]:
    IC[i] = OC[i]
    break

# print(IC)
# print(OC)
for i in range(N):
  IC[i] = min(IC[i], OC[i])
print(int(ceil(max(IC))))

# remove the worst incoming cost