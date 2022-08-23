H, W = tuple(map(int, input().split()))

i, j = 0, 0

G = [input() for i in range(H)]
# print(G)

dY = {"U": -1, "L": 0, "D": 1, "R": 0}
dX = {"U": 0, "L": -1, "D": 0, "R": 1}
memo = {(0, 0)}

while True:
  cmd = G[i][j]

  ii, jj = i+dY[cmd], j+dX[cmd]

  if (ii, jj) in memo:
    # print(memo)
    print(-1)
    break
  if ii in [-1, H] or jj in [-1, W]:
    # print(memo)
    print(i+1, j+1)
    break
  memo.add((ii, jj))
  i, j = ii, jj

