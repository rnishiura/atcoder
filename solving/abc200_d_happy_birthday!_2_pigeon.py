from copy import deepcopy
from itertools import product

def o2i(onehot):
  ret = []
  for i in range(len(onehot)):
    if onehot[i] == 1:
      ret.append(i+1)
  return ret

def main():
  MOD = 200
  N = min(int(input()), 8)
  A = list(map(int, input().split()))

  m = {}

  for c in product((1, 0), repeat=N):
    if c == tuple([0] * N):
      continue
    # print(c)
    s = 0
    c = o2i(c)
    # print(c)
    for i in c:
      s += A[i-1]
      s %= MOD
    if s in m:
      print("Yes")
      print(len(c), *c, sep=" ")
      print(len(m[s]), *m[s], sep=" ")
      return
    else:
      m[s] = c
  
  print("No")

main()

# cnt = 0
# for i in product([0, 1], repeat=200):
#   if cnt > 200:
#     break
#   print(i)
#   cnt += 1
