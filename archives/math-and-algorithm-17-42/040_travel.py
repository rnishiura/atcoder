N = int(input())
A = list(map(int, input().split()))

for i in range(1, N-1):
  A[i] += A[i-1]

M = int(input())

b = []
for i in range(M):
  b.append(int(input()) - 1)

# print()

D = 0
for i in range(1, M):
  newB = b[i]
  B = b[i-1]
  
  if newB == 0 and B == 0:
    diff = 0
  elif newB == 0:
    diff = A[B-1]
  elif B == 0:
    diff = A[newB-1]
  else: 
    diff = abs(A[B-1]-A[newB-1])
  # print(diff)
  D += diff

print(D)