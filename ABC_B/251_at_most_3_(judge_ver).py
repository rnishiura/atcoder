N, W = list(map(int, input().split(' ')))
A = list(map(int, input().split(' ')))

sums = []

# import itertools
# for i in range(1, 4):
#   for comb in itertools.combinations(A, i):
#     sums.append(sum(list(comb)))

# for p in range(len(A)):
#   sums.append(A[p])
#   for q in range(p+1, len(A)):
#     sums.append(A[p] + A[q])
#     for r in range(q+1, len(A)):
#       sums.append(A[p] + A[q] + A[r])

num = 0
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

# print(sums)

# num = 0

# for s in list(set(tuple(sums))):
#   if s <= W:
#     num += 1

print(num)