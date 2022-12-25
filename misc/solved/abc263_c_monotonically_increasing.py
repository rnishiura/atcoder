from itertools import combinations
N, M = tuple(map(int, input().split()))

for p in combinations(list(range(1, M+1)), N):
  print(' '.join(map(str, p)))

