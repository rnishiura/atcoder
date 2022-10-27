N, M = tuple(map(int, input().split()))
A = [[] for i in range(N+1)]

for i in range(M):
  a, b, c = tuple(map(int, input().split()))
  A[a].append((b, c))
  A[b].append((a, c))

PX = [1]
C = [10**18 for i in range(N+1)]
C[1] = 0

while PX != []:
  NX = []
  for f in PX:
    for t, c in A[f]:
      if C[f] + c < C[t]:
        C[t] = C[f] + c
        NX.append(t)
  PX = NX

PX = [N]
D = [10**18 for i in range(N+1)]
D[N] = 0

while PX != []:
  NX = []
  for f in PX:
    for t, c in A[f]:
      if D[f] + c < D[t]:
        D[t] = D[f] + c
        NX.append(t)
  PX = NX

for i in range(1, N+1):
  print(C[i] + D[i])
