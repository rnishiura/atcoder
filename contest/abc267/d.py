L = -400000000000000000000
N, M = tuple(map(int, input().split()))
A = list(map(int, input().split()))
NP = [L for i in range(M+1)]
NP[0] = 0
OP = [L for i in range(M+1)]
OP[0] = 0
C = 1

for i in range(N):
  for j in range(1, M+1):
    if j <= C:
      # print(OP[j-1], j*A[i])
      NP[j] = max(OP[j-1]+j*A[i], OP[j])
  NP, OP = OP, NP
  # print(OP)
  # print(NP)
  C += 1

print(OP[M])
