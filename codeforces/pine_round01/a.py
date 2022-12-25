t = int(input())

for i in range(t):
  n, a, b = tuple(map(int, input().split()))
  if a == b == n:
    print("Yes")
  elif a+b+2 <= n:
    print("Yes")
  else:
    print("No")