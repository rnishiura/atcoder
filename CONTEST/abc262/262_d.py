from itertools import product

MOD = 998244353
MAX = 500

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

def main():
  # cdef int i, n
  init()
  N = int(input())
  A = tuple(map(int, input().split()))
  
  cnt = 0

  for n in range(1, N+1):
    C = [0 for i in range(n)]
    for a in A: 
      C[a%n] += 1
    # for d in product([i for i in range(n)], repeat=n):
      CC = [0 for i in range(n)]
      for e in d:
        if CC[e] < C[e]:
          CC[e] += 1
        else:
          break
      else:
        tmp = 0
        for i in range(n):
          tmp += i*CC[i]
        if tmp % n != 0:
          continue
        tmp = 1
        for i in range(n):
          if CC[i] > 0:
            tmp = mul(tmp, cmb(C[i], CC[i]))
        cnt += tmp

  print(cnt)
    
main()
