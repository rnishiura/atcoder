N, Q = tuple(map(int, input().split()))

S = input()
C = [0 for _ in range(N+1)]

for i in range(N-1):
  if S[i] != S[i+1]:
    C[i+2] = C[i+1] + 1
  else:
    C[i+2] = C[i+1]

for _ in range(Q):
  L, R = tuple(map(int, input().split()))
  k = C[R]-C[L]
  if S[L-1] != S[R-1]:
    k += 1
  print((k+1)//2)