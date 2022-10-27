N, K = tuple(map(int, input().split()))
S = input()
T = sorted(zip(S, range(-N, 0)))
R = [0 for i in range(K)]
r = -K
for s, i in T:
  if r > -K and R[r-1] > i: continue
  R[max(i, r)] = i
  while r < 0 and R[r]: r += 1
  if r == 0: break
print("".join([S[i] for i in R]))