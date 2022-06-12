import numpy as np
N, K = [int(i) for i in input().split()]
A = [int(i)-1 for i in input().split()]

XY = []
for i in range(N):
  XY.append([int(i) for i in input().split()])

ans = 0
for i, xy in enumerate(XY):
  _min = 10e10
  for j, a in enumerate(A):
    dist = np.sqrt( (XY[a][0]-xy[0])**2 + (XY[a][1]-xy[1])**2 )
    if _min > dist:
      _min = dist
  if ans < _min:
    ans = _min

print(ans)
