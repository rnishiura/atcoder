def main():
  N, P, Q, R = tuple(map(int, input().split()))
  A = [0] + list(map(int, input().split()))
  S = [0 for i in range(N+1)]
  for i in range(1, N+1):
    S[i] = A[i] + S[i-1]

  # print(P+Q+R)

  
  y, z, w = 0, 0, 0
  for x in range(N):
    # y = x+1
    while y < N and S[y]-S[x] < P:
      y += 1
    if not S[y]-S[x] == P:
      continue
    # z = y+1
    while z < N and S[z]-S[x] < P+Q:
      z += 1
    if not S[z]-S[x] == P+Q:
      continue
    # w = z+1
    while w < N and S[w]-S[x] < P+Q+R:
      w += 1
    if S[w]-S[x] == P+Q+R:
      print("Yes")
      return
  else:
    print("No")

# print(memo)
# print(S[10]-S[1])

main()