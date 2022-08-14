N = int(input())

A = [input() for i in range(N)]

# print("###")

for j in range(N):
  for i in range(N-1, -1, -1):
    print(A[i][j], end="")
  print()
