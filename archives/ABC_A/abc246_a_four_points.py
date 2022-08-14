x = []
for i in range(3):
  x.append(tuple(map(int, input().split())))

if x[0][0] == x[1][0] or x[0][1] == x[1][1]:
  if x[0][0] == x[2][0] or x[0][1] == x[2][1]:
    a, b, c = 0, 1, 2
  else:
    a, b, c = 1, 0, 2
else:
  a, b, c = 2, 1, 0

print(f"{x[b][0]+x[c][0]-x[a][0]} {x[b][1]+x[c][1]-x[a][1]}")