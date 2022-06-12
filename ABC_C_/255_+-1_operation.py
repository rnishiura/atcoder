import numpy as np

X, A, D, N = map(int, input().split())

if D == 0:
  ans = abs(X-A)
else:
  k = (X-A) // D
  if k < 0:
    k = 0
    ans = abs(X-A-k*D)
  elif k > N-1:
    k = N-1
    ans = abs(X-A-k*D)
  else:
    ans = abs(X-A-k*D)
    for i in range(-2, 3):
      ans = min( ans, abs(X-A-(k+i)*D) )

print(ans)