H, W, rs, cs = tuple(map(int, input().split()))
N = int(input())
UD = {}
LR = {}

def bs(n, A, ll, rl):
  L = 0
  R = len(A)
  while True:
    M = (L+R)//2
    if A[M] < n:
      L = M
    else:
      R = M

    if L+1 >= R:
      retl = A[L] if L
      return A[L], A[R]

for i in range(N):
  r, c = tuple(map(int, input().split()))
  if not r in UD:
    UD[r] = [c]
  else:
    UD[r].append(c)
  if not c in LR:
    LR[c] = [r]
  else:
    LR[c].append(r)
  
Q = int(input())
r, c = rs, cs
for i in range(Q):
  d, l = tuple(map(int, input().split()))

  if not i in X:
    if d == "U": r = 1
    if d == "D": r = H
    if d == "L": c = 1
    if d == "R": c = W
    continue

