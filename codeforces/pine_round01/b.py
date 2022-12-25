t = int(input())

for _ in range(t):
  n = int(input())
  a = tuple(map(int, input().split()))
  
  if n == 1:
    print(1)
    continue
  if n % 2 == 1:
    print(n)
    continue
  b = a[:2]
  for i in range(n):
    if a[i] != b[i%2]:
      print(n)
      break
  else:
    print(n//2 + 1)
  