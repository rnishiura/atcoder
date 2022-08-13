MOD = 1000000007
N = int(input())

INV = 1
K = MOD // 10**3
M33 = 3**10**3 % MOD
for i in range(K):
  INV *= M33
  INV %= MOD

for i in range(MOD % 10**3 - 2):
  INV *= 3
  INV %= MOD

# print(INV)
# print((INV*3)%MOD)

U = 1
N %= MOD-1
K = N // 10**3

M43 = 4**10**3 % MOD
for i in range(K):
  U += M43
  U %= MOD

N = N % 10**3
for i in range(N+1):
  U *= 4
  U %= MOD

print(((U-1)*INV)%MOD)