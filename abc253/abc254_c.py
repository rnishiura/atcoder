Q = int(input())

m = [False for i in range(int(10e9+1))]

l = {}

for i in range(Q):
  query = [int(i) for i in input().split(' ')]
  
  if query[0] == 1:
    if query[1] in l:
      l[query[1]] += 1
    else:
      l[query[1]]  = 1
    
    m[query[1]] = True

  if query[0] == 2:
    if not query[1] in l:
      l[query[1]] = 0
    c = min(l[query[1]], query[2])
    l[query[1]] -= c
    if l[query[1]] == 0:
      m[query[1]] = False

  if query[0] == 3:
    mn = 10e9
    mx = -1
    for i in range(len(m)):
      if mx < m[i]:
        mx = m[i]
      if mn > m[i]:
        mn = m[i]
    print(mx - mn)
    pass