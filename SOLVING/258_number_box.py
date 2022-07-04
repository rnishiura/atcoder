from itertools import product
N = int(input())
B = [[] for i in range(10)]
A = []
best_1st = 0
for i in range(N):
  t = input()
  A.append(t)
  for j, a in enumerate(t):
    a = int(a)
    best_1st = max(a, best_1st)
    B[a].append((i, j))

# print(best_1st)
# print(A)
# print(B)

best = 0
for y, x in B[best_1st]:
  for dx, dy in product([-1,0,1],[-1,0,1]):
    if dx == 0 and dy == 0: continue
    snum = str(best_1st)
    xx, yy = x, y
    # print(xx, yy)
    for i in range(N-1):
      xx, yy = (xx+dx)%N, (yy+dy)%N
      snum += str(A[yy][xx])
    best = max(best, int(snum))

print(best)