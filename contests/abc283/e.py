H, W = tuple(map(int, input().split()))

A = [tuple(map(int, input().split())) for _ in range(H)]

DP = []
for i in range(H-1):
  inST = False
  inS = False
  inT = False
  for j in range(W):
    S = []
    if i <= H-2:
      S += [A[i+1][j]]
    if 1 <= j:
      S += [A[i][j-1]]
    if i <= W-2:
      S += [A[i][j+1]]
    T = []
    if i <= H-2:
      T += [A[i+1][j]]
    if 1 <= j:
      T += [1-A[i][j-1]]
    if i <= W-2:
      T += [1-A[i][j+1]]
    if A[i][j] in S and A[i][j] in S:
      inST = True
    else if A[i][j] in S:
      inS = True
    else if A[i][j] in T:
      inT = True
  if inST:
    
  
      