X, Y = tuple(map(int, input().split()))

X, Y = min(X, Y), max(X, Y)

if X+3 > Y:
  print("Yes")
else:
  print("No")
  