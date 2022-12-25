t = int(input())

for _ in range(t):
  a = list(map(int, input().split()))
  print(sorted(a)[1])
  