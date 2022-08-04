MOD = 998244353
MAX = 500000

fact      = [1 for i in range(MAX)]
inv_fact  = [1 for i in range(MAX)]
inv       = [1 for i in range(MAX)]

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
  return a * b % MOD

if __name__ == "__main__":
  init()
  N = int(input())
  C = 0
  for K in range(N, N*N-N+1+1):
    C += cmb(K-1, N-1) * cmb(N*N-K, N-1) % MOD
  
  print( (fact[N*N] - mul(mul(mul(fact[N], fact[N]), fact[(N-1)**2]), C)) % MOD )