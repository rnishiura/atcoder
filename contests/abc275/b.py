MOD = 998244353
A = tuple(map(int, input().split()))

B = [a % MOD for a in A]
print(((((B[0]*B[1])%MOD)*B[2]%MOD)-(((B[3]*B[4])%MOD)*B[5]%MOD))%MOD)