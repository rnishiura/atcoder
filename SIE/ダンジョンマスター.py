k = int(input())

n, m = 40, 50

ans = [['#' for j in range(m)] for i in range(n)]

cnt = 0
y, x = 0, 0

mcnt = 0
mode = 'R'
while cnt < k:
  if mode in ['L', 'R'] and mcnt == m-1:
    mode = 'D'
    mcnt = 0
  if mode == 'D' and mcnt == 2:
    if x == m-1: mode = 'L'
    if x == 0  : mode = 'R'
    mcnt = 0

  if mode == 'R': x += 1
  if mode == 'L': x -= 1
  if mode == 'D': y += 1

  ans[y][x] = '.'

  # print(y, x)
  mcnt += 1
  cnt += 1

ans[0][0] = 'S'
ans[y][x] = 'G'

print(n, m)
for i in range(n):
  print("".join(ans[i]))
