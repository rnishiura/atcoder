N = int(input())
L = ["M","A","R","C","H"]
C = {}
for c in L:
  C[c] = 0
  
for i in range(N):
  S = input()
  if S[0] in C:
    C[S[0]] += 1
  else:
    C[S[0]] = 1

ret = 0
for i in range(5):
  for j in range(i+1, 5):
    for k in range(j+1, 5):
      ret += C[L[i]]*C[L[j]]*C[L[k]]

print(ret)
