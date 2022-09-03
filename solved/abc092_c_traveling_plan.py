N = int(input())
A = [0] + list(map(int, input().split())) + [0]
A = tuple(A)

ans = 0
for i in range(1, N+2):
  ans += abs(A[i]-A[i-1])

for i in range(1, N+1):
  print(ans - abs(A[i]-A[i-1]) - abs(A[i+1]-A[i]) + abs(A[i+1]-A[i-1]))

