N = int(input())
A = tuple(map(int, input().split()))

o1, o2, e1, e2 = -1, -1, -1, -1
for k in A:
  if k % 2:
    m = sorted([o1, o2, k])
    o1 = m[2]
    o2 = m[1]
  else:
    m = sorted([e1, e2, k])
    e1 = m[2]
    e2 = m[1]

r = [-1]
if e2 >= 0:
  r.append(e1+e2)
if o2 >= 0:
  r.append(o1+o2)

print(max(r))