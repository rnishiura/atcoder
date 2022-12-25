N, K = tuple(map(int, input().split()))
A = list(map(int, input().split()))
A += [0] * K
print(*A[-N:], sep=" ")