A, B = input().split()

if len(A) < len(B):
  A, B = B, A

A = A[::-1]
B = B[::-1]

for i in range(len(B)):
  a = int(A[i])
  b = int(B[i])
  if a+b >= 10:
    print("Hard")
    break
else:
  print("Easy")
  