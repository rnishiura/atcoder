B = '#'
H = '.'

k = int(input())

n, m = 50, 50

ans = [[B for j in range(m)] for i in range(n)]

for i in range(m):
  ans[0][i] = H
  ans[n-1][i] = H

for i in range(n):
  ans[i][0] = H
  ans[i][m-1] = H

y, x = 2, 2

ans[2][2] = H

dx, dy = 1, 0

for _ in range(k):
  if ans[y+2*dy][x+2*dx] == H: 
    dx, dy = -dy, dx
  y, x = y+dy, x+dx
  ans[y][x] = H

ans[2][2] = 'S'
ans[y][x] = 'G'

print(n, m)
for i in range(n):
  print("".join(ans[i]))
