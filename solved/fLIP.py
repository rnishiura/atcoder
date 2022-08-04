N, M, K = tuple(map(int, input().split()))

for i in range(N+1):
  for j in range(M+1):
    if i*(M-j) + j*(N-i) == K:
      print("Yes")
      break
  else:
    continue
  break
else:
  print("No")
