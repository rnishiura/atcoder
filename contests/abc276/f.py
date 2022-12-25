N = int(input())
A = tuple(map(int, input().split()))

MOD = 998244353

def inv(n):
  if n == 1:
    return 1
  else:
    return MOD - inv(MOD%n) * (MOD//n) % MOD

def ans(x, y):
  return (inv(x) * y%MOD) % MOD

print(ans(4, 26))
print(ans(9, 55))


for k in range(1, N+1):
