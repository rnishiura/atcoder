import math
H, W = [int(i) for i in input().split(' ')]

l = []
for i in range(H):
  s = input()
  for j in range(W):
    if s[j] == 'o':
      l.append((i, j))
      if len(l) == 2:
        break
  if len(l) == 2:
    break

print( int( math.fabs(l[0][0]-l[1][0]) + math.fabs(l[0][1]-l[1][1]) ) )