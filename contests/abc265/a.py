X, Y, N = tuple(map(int, input().split()))

if Y < X*3:
  print(Y * (N // 3) + X * (N % 3))
else :
  print(N * X)

