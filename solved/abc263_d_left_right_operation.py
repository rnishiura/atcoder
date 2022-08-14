from numpy import inf

N, L, R = tuple(map(int, input().split()))
A = list(map(int, input().split()))
A.insert(0, 0)

min_val = inf
f = 0
for i in range(N+1):
  f = min(f+A[i], L*i)
  min_val = min(min_val, f + (N-i)*R)

print(min_val)