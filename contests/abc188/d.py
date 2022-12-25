N, C = tuple(map(int, input().split()))

A = []
for i in range(N):
  a, b, c = tuple(map(int, input().split()))
  A.append((a, c, True))
  A.append((b+1, c, False))

A.sort()

sum_val = 0
l, P, la = A[0]

for d, c, s in A[1:]:
  sum_val += (d-l) * min(P, C)
  if s:
    P += c
  if not s:
    P -= c
  l = d

print(sum_val)