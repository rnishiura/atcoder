N = int(input())
Q = [(0,0)]

for i in range(N):
  q = tuple(map(int, input().split()))
  if q[0] == 1:
    a, b = q[1], q[2]

    Q.sort()
    L = 0, R = len(Q)
    while True:
      M = (L+R) // 2
      if Q[M][0] <= a:
        L = M
      else:
        R = M

      if L + 1 >= R:
        break

    if Q[R][0] <= a:
      M = R
    else:
      M = L

  QQ = Q[:M+1]
  sort(QQ, key=lambda x: x[1])
  L = 0, R = len(QQ)
  while True:
    M = (L+R) // 2
    if QQ[M][0] <= a:
      L = M
    else:
      R = M

    if L + 1 >= R:
      break

  if QQ[R][0] <= a:
    M = R
  else: 
    M = L

  c = len(QQ[:M+1])
  print(c)