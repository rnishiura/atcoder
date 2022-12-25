def solve():
  n = int(input())
  rank = [0 for i in range(n)]
  rrank = [[] for i in range(n)]
  d = []
  for i in range(n):
    s = input()
    n1 = 0
    for c in s:
      if c == "1":
        n1 += 1
    rank[i] = n1
    rrank[n1].append(i)
    d.append(s)

  # print(rank)
  # print(rrank)

  ret = {rrank[0][0]: list(range(n))}
  decay = [-1 for i in range(n)]
  for i in range(1, n):
    # print(i)
    rainbow = False
    for j in rrank[i]:
      max_rank = 0
      for k, c in enumerate(d[j]):
        if c == "1":
          max_rank = max(max_rank, rank[k])
      for k, c in enumerate(d[j]):
        if c == "1" and rank[k] == max_rank:
          if rainbow:
            k = prev
          pset = list(ret[k])
          pset.remove(pset[decay[k]])
          ret[j] = pset
          decay[k] -= 1
          break
      rainbow = True
      prev = j

  
  for i in range(n):
    print(len(ret[i]), end=" ")
    for v in ret[i]:
      print(v+1, end=" ")
    print()
    
t =  int(input())
for _ in range(t):
  solve()