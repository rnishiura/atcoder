N, M, K = tuple(map(int, input().split()))

MOD = 998244353

def inv(n):
  if n == 1:
    return 1
  else:
    return MOD - inv(MOD%n) * (MOD//n) % MOD

def ans(x, y):
  return (inv(x) * y%MOD) % MOD

# print(ans(2, 1))

A = [[0 for i in range(N+1)] for j in range(K+1)]
A[0][0] = 1

for i in range(1, K+1):
  for j in range(N):
    for k in range(M):
      A[i][j+k+1 if j+k+1 <= N else 2*N - (j+k+1)] += A[i-1][j]
      A[i][j+k+1 if j+k+1 <= N else 2*N - (j+k+1)] %= MOD 

invM = inv(M)

def f(n):
  x = 1
  for i in range(n):
    x *= invM
    x %= MOD
  p = (x * A[n][N]) % MOD
  if n == K:
    return p
  else:
    return (p + f(n+1)) % MOD

print(f(1))
