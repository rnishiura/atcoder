MOD = 1000000007
S = input()
chokudai = "chokudai"
D = [[0 for j in range(9)] for i in range(len(S)+1)]
for i in range(len(D)):
  D[i][0] = 1


for i in range(1, len(S)+1):
  j = chokudai.find(S[i-1]) + 1
  for k in range(1, 9):
    if k == j:
      D[i][k] = D[i-1][k] + D[i][k-1]
    else:
      D[i][k] = D[i-1][k]
    D[i][k] %= MOD

print(D[len(S)][8])
