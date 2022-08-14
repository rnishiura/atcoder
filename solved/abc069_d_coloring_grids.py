H, W = tuple(map(int, input().split()))
N = int(input())
a = tuple(map(int, input().split()))

B = [[0 for i in range(W)] for j in range(H)]
l = 0
s = 0

for i in range(H):
  for j in range(W):
    if i % 2:
      j = W - j - 1
    if s == a[l]:
      s = 0
      l += 1
    B[i][j] = l+1
    s += 1

for b in B:
  print(*b, sep=" ")