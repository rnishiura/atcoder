t = int(input())
for _ in range(t):
  n = int(input())
  a = tuple(map(int, input().split()))
  
  so = 0
  sz = 0
  for v in a:
    if v == 0:
      sz += 1
    else:
      so += 1
  o = 0
  z = 0
  d = 0
  s = 0
  for v in a:
    if v == 0:
      z += 1
      d = max(d, sz-z-o)
    else:
      d = max(d, o-(sz-z))
      o += 1
      s += sz-z

  print(s+d)
