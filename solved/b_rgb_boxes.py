R, G, B, N = tuple(map(int, input().split()))

cnt = 0

for r in range(N+1):
  if r*R > N:
    break
  for g in range(N+1):
    if r*R+g*G > N:
      break
    if (N-r*R-g*G) % B == 0:
      cnt += 1

print(cnt)