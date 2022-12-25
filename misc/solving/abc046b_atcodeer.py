N, K = tuple(map(int, input().split()))
ret = K
for i in range(N-1):
  ret *= K-1

print(ret)