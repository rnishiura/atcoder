t = int(input())

for i in range(t):
  n, k = tuple(map(int, input().split()))
  if n == 5:
    ans = [0, 2, 4, 1, 5, 3][k]
  elif n&1:
    r = {1:2,2:3,3:1,n-2:n-1,n-1:n,n:n-2}
    if k in r.keys():
      ans = r[k]
    else:
      ans = k
  else:
    r = {1:2,2:1,n-1:n,n:n-1}
    if k in r.keys():
      ans = r[k]
    else:
      ans = k
  print(ans)
3