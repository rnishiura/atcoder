N, M, X, T, D = map(int, input().split())

if M-X >= 0:
  print(T)
else:
  print(T-(X-M)*D)
  