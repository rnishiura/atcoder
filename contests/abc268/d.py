from itertools import permutations

def room_member(M, R):
  if R > 1:
    ret = []
    for i in range(M+1):
      for r in room_member(i, R-1):
        ret.append([M-i] + r)
    return ret
  else:
    return [[M]]

def main():
  N, M = tuple(map(int, input().split()))
  S = [input() for i in range(N)]
  T = [input() for i in range(M)]
  T = set(T)

  MAX = 16
  MIN = 3

  LEN = 0
  for y in S:
    LEN += len(y)

  INT = len(S) - 1
  MAX_MEM = MAX - (LEN + INT)
  MIN_MEM = max(0, MIN - (LEN + INT))

  if not INT:
    if not S[0] in T and len(S[0]) >= MIN:
      print(S[0])
      return
    else:
      print(-1)
      return

  for p in permutations(S):
    for j in range(MIN_MEM, MAX_MEM+1):
      for r in room_member(j, INT):
        ret = p[0]
        # print(r)
        # print(p)
        for i, m in enumerate(r):
          ret += "_" + "_" * m + p[i+1]
        # print(ret)
        # raise ValueError()

        if not ret in T:
          print(ret)
          return
  print(-1)

main()