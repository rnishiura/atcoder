N, Q = tuple(map(int, input().split()))
A = list(map(int, input().split()))

for i in range(1, N):
  A[i] += A[i-1]

print()

for i in range(Q):
  L, R = tuple(map(int, input().split()))
  if L == 1:
    print(A[R-1])
  else:
    print(A[R-1] - A[L-2])