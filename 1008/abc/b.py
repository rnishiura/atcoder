N, M = tuple(map(int, input().split()))

A = [[False for i in range(N+1)] for j in range(N+1)]
for i in range(M):
  a = tuple(map(int, input().split()))
  for j in range(1, a[0]+1):
    for k in range(j+1, a[0]+1):
      A[a[j]][a[k]] = True
      A[a[k]][a[j]] = True

for i in range(N+1):
  A[i][i] = True

for i in range(1, N+1):
  for j in range(1, N+1):
    if A[i][j] == False:
      print("No")
      exit()

print("Yes")