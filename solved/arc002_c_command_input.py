from itertools import product
N = int(input())
S = input()

min_cnt = len(S)
for LR in product("ABXY", repeat=4):
  # print(LR)
  L = LR[0]+LR[1]
  R = LR[2]+LR[3]
  cnt = 0
  idx = 0
  while idx < N:
    if idx < N-1 and S[idx:idx+2] in [L, R]:
      idx += 2
    else:
      idx += 1
    cnt += 1
  # print(cnt)
  min_cnt = min(min_cnt, cnt)
print(min_cnt)
