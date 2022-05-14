# https://atcoder.jp/contests/abc251/tasks/abc251_b

N, W = list(map(int, input().split(' ')))
A = list(map(int, input().split(' ')))

# # # # # # # # # # # # # # # # # # # # # # # # # 

flg = [False for i in range(W+1)]

for p in range(len(A)):
  tmp = A[p]
  if tmp <= W:
    flg[tmp] = True
  else:
    continue

  for q in range(p+1, len(A)):
    tmp = A[p] + A[q]
    if tmp <= W:
      flg[tmp] = True
    else:
      continue

    for r in range(q+1, len(A)):
      tmp = A[p] + A[q] + A[r]
      if tmp <= W:
        flg[tmp] = True
      else:
        continue

num = 0
for w in flg:
  if w:
    num += 1

# # # # # # # # # # # # # # # # # # # # # # # # # 

print(num)