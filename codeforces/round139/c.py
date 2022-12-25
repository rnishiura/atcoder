t = int(input())

def solve2(s, c, upper=True):
  # print(s, c)
  cnt = 1
  y = 0 if upper else 1
  x = 0
  if s[y][x] != 'B':
    return False

  if cnt == c:
    return True

  last = (-1, -1)
  while True:
    # print(last)
    # print(x, y)
    if (last != (x, 1-y)) and s[1-y][x] == 'B':
      last = (x, y) 
      y = 1-y
    elif (last == (x, 1-y) or s[1-y][x] == "W") and x+1 < len(s[0]) and s[y][x+1] == 'B':
      last = (x, y)
      x += 1
    else:
      break
    cnt += 1
    if cnt == c:
      return True
  return False

def solve():
  m = int(input())
  s = [input() for _ in range(2)]

  cnt = 0
  for ss in s:
    for c in ss:
      if c == 'B':
        cnt+=1

  if solve2(s, cnt, True) or solve2(s, cnt, False):
    print("YES")
  else:
    print("NO")


for _ in range(t):
  solve()