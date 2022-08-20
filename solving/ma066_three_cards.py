N, K = tuple(map(int, input().split()))

if N - K >= 1:
  p = N**3 - (N-K+1) * K**2 - (2*K-1)*K*(K-1) // 6
else:
  p = 0

print(p)
