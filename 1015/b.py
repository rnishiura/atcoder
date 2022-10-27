X, K = tuple(map(int, input().split()))
X += 10**15
R = X
S = str(R)
for i in range(K):
  j = int(S[-1-i])
  R -= j * 10**i
  if j >= 5:
    R += 10**(i+1)
    S = str(R)
  # print(S)

print(R - 10**15)