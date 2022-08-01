N = 3

ans = 1
for i in range(1, N+1):
  ans = ans * i % 998244353

for i in range(2*N-1):
  ans = ans * 2 % 998244353

print(ans)