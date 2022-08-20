A, B = input().split()

A = A[::-1]
B = B[::-1]

ans = 0

for i in range(len(B)):
  tmp = 0
  for j in range(len(A)):
    a, b = int(A[j]), int(B[i])
    tmp += a * b * 10**j
  ans += tmp * 10**i

print(ans)