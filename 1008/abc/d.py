from math import sqrt
N, M = tuple(map(int, input().split()))

A = [[-1 for j in range(N)] for i in range(N)]

dx, dy = 401, 401
D = []
for i in range(401):
  for j in range(i, 401):
    if i**2 + j**2 == M:
      D.append((i, j))
      break

d = []
for dx, dy in D:
  d += [(dx, dy), (dy, dx), (-dx, dy), (-dy, dx),(-dx, -dy), (-dy, -dx),(dx, -dy), (dy, -dx)]

A[0][0] = 0
PX = [(0, 0)]
cnt = 1
while PX != []:
  NX = []
  for p, q in PX:
    for dx, dy in d:
      if 0 <= p+dx < N and 0 <= q+dy < N:
        if A[q+dy][p+dx] == -1:
          A[q+dy][p+dx] = cnt
          NX.append((q+dy, p+dx))
  PX = NX
  cnt += 1

for a in A:
  print(*a, sep=" ")

