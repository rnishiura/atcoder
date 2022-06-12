import numpy as np
N, K = [int(i) for i in input().split(' ')]
A = [int(i) for i in input().split(' ')]
# A = np.array(A).reshape()
sA = [[A[i] for i in range(k, N, K)] for k in range(K)]

# print(sA)
for s in sA:
  s.sort()
# sA.sort()
# print(sA)
B = []
for i in range(len(sA[0])):
  for k in range(K):
    if i < len(sA[k]):
      B.append(sA[k][i])

# raise ValueError()
flg = True
# for i in range(N-K):
#   a, b = A[i], A[i+K] 
#   A[i]   = min(a, b)
#   A[i+K] = max(a, b)

for i in range(N-1):
  if(B[i] > B[i+1]):
    flg = False

# print(B)

if flg:
  print('Yes')
else:
  print('No')