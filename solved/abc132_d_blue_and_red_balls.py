MOD = 1000000007
MAX = 2000

fact      = [1 for i in range(MAX+1)]
inv_fact  = [1 for i in range(MAX+1)]
inv       = [1 for i in range(MAX+1)]

def init():
  global fact, inv_fact, inv
  for i in range(2, MAX):
    fact[i] = fact[i-1] * i % MOD
    inv[i]  = MOD - inv[MOD%i] * (MOD//i) % MOD
    inv_fact[i] = inv_fact[i-1] * inv[i] % MOD

def cmb(n, k):
  global fact, inv_fact, inv
  x = fact[n] 
  y = inv_fact[n-k]
  z = inv_fact[k]
  if n < k or n < 0 or k < 0: return 0
  return x * ((y * z) % MOD) % MOD

def mul(a, b):
  return (a%MOD) * (b%MOD) % MOD

def add(a, b):
  return ((a%MOD) + (b%MOD)) % MOD

if __name__ == "__main__":
  init()
  N, K = tuple(map(int, input().split()))
  L = N-K
  print(L+1)
  for i in range(2, min(K, L+1)+1):
    ans = cmb(K-1, i-1)
    sum = 0
    for m in range(L-i+2):
      sum += mul(cmb(i-2+m, m), L-(i-1)+1-m)
      sum %= MOD
    ans = mul(ans, sum)
    print(ans)

  for i in range(min(K, L+1)+1, K+1):
    print(0)