N, Q = tuple(map(int, input().split()))
L, R = [], []

for i in range(Q):
  l, r, x = tuple(map(int, input().split()))
  L.append((l-1, x))
  R.append((r-1, x))

L.sort()
R.sort()

lc, rc, X = 0, 0, 0

for i in range(N):
  diff = 0
  while lc < Q and L[lc][0] == i:
    diff += L[lc][1]
    lc += 1
  while rc < Q and R[rc][0] == i-1:
    diff -= R[rc][1]
    rc += 1
  if i==0:
    continue
  if diff > 0:
    print("<", end="")
  elif diff == 0:
    print("=", end="")
  else:
    print(">", end="")

  # X += diff
  # print(X)
print()