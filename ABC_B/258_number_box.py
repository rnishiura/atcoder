from itertools import product

N = int(input())
A = []
B = [[] for i in range(10)]

best_1st = 0
for i in range(N):
  t = input()
  A.append(t)
  for j, a in enumerate(t):
    best_1st = max(int(a), best_1st)
    B[int(a)].append((i, j))

best = 0
for y, x in B[best_1st]:
  for dx, dy in product([-1,0,1], repeat=2):
    if dx == 0 and dy == 0: continue

    snum = "".join([A[(y+i*dy)%N][(x+i*dx)%N] for i in range(N)])
    best = max(best, int(snum))

print(best)