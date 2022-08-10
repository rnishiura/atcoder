N, K = tuple(map(int, input().split()))
A = []
for i in range(N):
  A.append(input())

# move
print(0)
# for i in range(N):
#   cnt = 0
#   for j in range(N):

# connect
connect = []
for i in range(N-1):
  for j in range(N-1):
    if A[i][j] == "0":
      continue
    if A[i][j] == A[i+1][j]:
      connect.append((i, j, i+1, j))
    if A[i][j] == A[i][j+1]:
      connect.append((i, j, i, j+1))

print(len(connect))
for c in connect:
  print(" ".join(map(str, c)))

