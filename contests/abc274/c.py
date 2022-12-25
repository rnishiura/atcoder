N = int(input())
A = [0] + list(map(int, input().split()))
B = [0 for i in range(2*N+2)]

for i in range(1, N+1):
  B[2*i] = B[A[i]]+1
  B[2*i+1] = B[A[i]]+1

print(*B[1:], sep="\n")