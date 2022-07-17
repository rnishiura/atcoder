N = int(input())
A = tuple(map(int, input().split()))
DP = [None for i in range(200)]
DP[0] = []

ret = []
for i in range(N):
  newDP = DP.copy()
  for j in range(200):
    if DP[j] != None:
      if not DP[(j+A[i])%200] in [None, []]:
        ret = [DP[(j+A[i])%200], DP[j]]
        ret[1].append(i+1)
        break
      newDP[(j+A[i])%200] = DP[j].copy()
      newDP[(j+A[i])%200].append(i+1)
  else:
    DP = newDP
    continue
  print("Yes")
  for i in range(2):
    ret[i].insert(0, len(ret[i]))
    print(*ret[i], sep=" ")
  break
else:
  print("No")