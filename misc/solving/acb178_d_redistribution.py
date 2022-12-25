S = int(input())

N = S // 3
opt = S % 3 != 0

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

  print(opt)

  ans = 0
  for i in range(N):
    mpl = cmb(N-1, i)
    if opt:
      mpl *= i+1
      # mpl %= MOD
    ans += mpl
    ans %= MOD
  
  print(ans)
