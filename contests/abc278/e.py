H, W, N, h, w = tuple(map(int, input().split()))

A = [tuple(map(int, input().split())) for i in range(H)]

# C = [0 for i in range(N+1)]
# for i in range(H):
#   for j in range(W):
#     C[A[i][j]] += 1

# B = 0
# for i in range(N+1):
#   if C[i] >= 0:
#     B += 1

R = [[0 for i in range(W-w+1)] for j in range(H-h+1)]
# for i in range(h):
#   for j in range(w):
#     C[A[i][j]] -= 1
#     if C[A[i][j]] == 0:
#       B -= 1

for i in range(H-h+1):
  B = 0
  C = [0 for i in range(N+1)]
  for j in range(H):
    for k in range(W):
      C[A[j][k]] += 1
  # print(C)
  for j in range(N+1):
    if C[j] > 0:
      B += 1
  # print(B)
  for j in range(h):
    for k in range(w):
      C[A[i+j][k]] -= 1
      if C[A[i+j][k]] == 0:
        B -= 1
  # print(C)
  # print(B)
  R[i][0] = B
  for j in range(0, W-w):
    for k in range(h):
      C[A[i+k][j]] += 1
      if C[A[i+k][j]] == 1:
        B += 1
      C[A[i+k][j+w]] -= 1
      if C[A[i+k][j+w]] == 0:
        B -= 1
    R[i][j+1] = B

for i in range(H-h+1):
  for j in range(W-w+1):
    print(R[i][j], end=" ")
  print()