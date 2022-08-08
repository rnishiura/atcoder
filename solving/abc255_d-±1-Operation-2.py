# 二分探索と累積和
N, Q = tuple(map(int, input().split()))
A = list(map(int, input().split()))
A.insert(0, 0)
A.sort()
# print(A)
S = [0 for i in range(N+1)]
for i in range(1, N+1):
  S[i] = S[i-1] + A[i]
# print(S)

for i in range(Q):
  x = int(input())

  l, r = 0, N
  while l+1 < r:
    m = (l+r) // 2
    if A[m] <= x:
      l = m
    else:
      r = m
  
  if A[r] <= x:
    j = r
  else:
    j = l
  # print(j)
  print(x*j-S[j]+S[N]-S[j]-x*(N-j))