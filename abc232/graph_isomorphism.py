# https://atcoder.jp/contests/abc232/tasks/abc232_c

import itertools
import math

n, m = list(map(int, input().split(' ')))
ab = []
for i in range(m):
  ab.append(tuple(map(int, input().split(' '))))
cd = []
for i in range(m):
  cd.append(tuple(map(int, input().split(' '))))

# print(ab)
# print(cd)

cd.sort()

ball_labels = [i+1 for i in range(n)]

flg = False
for p in itertools.permutations(ball_labels):
  # abをpにマップする
  tmp = [(min(p[s-1], p[t-1]), max(p[s-1], p[t-1])) for s, t in ab]
  # print(p)
  tmp.sort()
  # print(tmp)
  # cdのアナグラムに重なればyes
  if tmp == cd:
    flg = True
    break

if flg:
  print("Yes")
else:
  print("No")