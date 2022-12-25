H, M = tuple(map(int, input().split()))

while True:
  while True:
    A = H // 10
    B = H % 10
    C = M // 10
    D = M % 10
    if 0 <= 10*A+C <= 23 and 0 <= 10*B+D <= 59:
      print(H, M)
      exit()
    M += 1
    M %= 60
    if M == 0:
      break
  H += 1
  H %= 24