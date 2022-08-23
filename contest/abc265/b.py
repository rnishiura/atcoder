N, M, T = tuple(map(int, input().split()))
A = tuple(map(int, input().split()))

B = [0 for i in range(N+1)]

for i in range(M):
  X, Y = tuple(map(int, input().split()))
  B[X] = Y

for i in range(N-1):
  if T <= A[i]:
    print("No")
    break
  T += B[i+2] - A[i]
else:
  print("Yes")