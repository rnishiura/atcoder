N, W = map(int, input().split())

KW = [0 for i in range(W+1)]

for i in range(N):
  w, v = map(int, input().split())
  for j in range(W, 0, -1):
    if j >= w:
      KW[j] = max(KW[j], v+KW[j-w])

print(KW[W])
