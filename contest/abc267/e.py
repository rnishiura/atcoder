MAX = 100000000000000000000
N, M = tuple(map(int, input().split()))
A = [0] + list(map(int, input().split()))
S = [0 for i in range(N+1)]

CC = {}

for i in range(M):
  u, v = tuple(map(int, input().split()))
  S[u] += A[v]
  S[v] += A[u]
  if u in CC:
    CC[u].append(v)
  else:
    CC[u] = [v]
  if v in CC:
    CC[v].append(u)
  else:
    CC[v] = [u]

# print(S)
# print(CC)
max_val = 0
S[0] = MAX
for i in range(N):
  j = S.index(min(S))
  max_val = max(max_val, S[j])
  S[j] = MAX
  for c in CC[j]:
    S[c] -= A[j]
  
print(max_val)
