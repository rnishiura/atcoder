t = int(input())
for _ in range(t):
  n = int(input())
  a = tuple(map(int, input().split()))
  l = n
  r = 0
  for i in range(1, n):
    if a[i-1] < a[i]:
      l = i
      break
  for i in range(n-2, 0, -1):
    if a[i] > a[i+1]:
      r = i
      break
  if l <= r:
    print("NO")
  else:
    print("YES")
