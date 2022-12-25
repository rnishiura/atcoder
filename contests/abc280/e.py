MOD = 998244353

def inv(n):
  if n == 1:
    return 1
  else:
    return MOD - inv(MOD%n) * (MOD//n) % MOD
 
def ans(x, y):
  return (inv(x) * y%MOD) % MOD

N, P = tuple(map(int, input().split()))

print(ans(P+100, 100*N))