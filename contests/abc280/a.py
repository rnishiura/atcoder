H, W = tuple(map(int, input().split()))

cnt = 0
for i in range(H):
  s = input()
  for j in range(W):
    if s[j] == '#':
      cnt += 1

print(cnt)