from itertools import combinations
N, M = tuple(map(int, input().split()))

L = list(range(1, M+1))

for p in combinations(L, N):
  print(" ".join(map(str, p)))
