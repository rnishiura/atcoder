MOD = 998244353
N, M = tuple(map(int, input().split()))
P = tuple(map(int, input().split()))

# calc bind
C = [False for i in range(N)]
for i in range(N):
  if i+1 == P[i]:
    C[i] = True

REST = [0 for i in range(N+1)]
REST[N] = 1
for i in range(N-1, 0, -1):
  REST[i] = REST[i+1]*M%MOD if C[i] == True else REST[i+1]*M*M%MOD

HEAD = [0 for i in range(N+1)]
HEAD[-1] = 1
for i in range(1, N):
  HEAD[i] = HEAD[i-1]*M%MOD

cnt = 0
for i in range(N):
  if C[i]: continue
  cnt += HEAD[i-1] * M * (M-1) // 2 * REST[i+1]
  cnt %= MOD

print(HEAD)
print(REST)
print(cnt)