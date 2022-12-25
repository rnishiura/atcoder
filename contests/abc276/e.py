H, W = tuple(map(int, input().split()))

A = ['#' * (W+2)] + ["#" + input() + "#" for i in range(H)] + ['#' * (W+2)]

# print(A)

for i in range(H+2):
  for j in range(W+2):
    if A[i][j] == "S":
      ys, xs = i, j
      break
  else:
    continue
  break

delta = [(1, 0), (-1, 0), (0,1), (0,-1)]
all_history = {(ys, xs)}

for dy, dx in delta:
  if A[ys+dy][xs+dx] == '.':
    history = {(ys, xs), (ys+dy, xs+dx)}
    f = [(ys+dy, xs+dx)]
    while f != []:
      t = []
      for y, x in f:
        for dy, dx in delta:
          if A[y+dy][x+dx] == '.' and not (y+dy, x+dx) in history:
            t.append((y+dy, x+dx))
            history.add((y+dy, x+dx))
            if (y+dy, x+dx) in all_history:
              print("Yes")
              exit()
      f, t = t, f
    all_history = all_history.union(history)
    # print(history)
    
# print(all_history)
print("No")
