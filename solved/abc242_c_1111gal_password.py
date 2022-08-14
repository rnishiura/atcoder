N = int(input())
MOD = 998244353

a1, a2, a3, a4, a5 = 1, 1, 1, 1, 1

for i in range(1, N):
  na1 = a1 + a2
  na2 = a1 + a2 + a3
  na3 = a2 + a3 + a4
  na4 = a3 + a4 + a5
  na5 = a4 + a5 + a4
  a1, a2, a3, a4, a5 = na1%MOD, na2%MOD, na3%MOD, na4%MOD, na5%MOD

print((2*(a1+a2+a3+a4)+a5)%MOD)