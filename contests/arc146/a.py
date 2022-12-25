from itertools import permutations

N = int(input())
T = tuple(map(int, input().split()))

A, B, C = 0, 0, 0
for t in T:
  if t >= A:
    C = B
    B = A
    A = t
  elif t >= B:
    C = B
    B = t
  elif t >= C:
    C = t

S = [str(A), str(B), str(C)]

max_val = 0
for s in permutations(S):
  max_val = max(max_val, int(s[0]+s[1]+s[2]))

print(max_val)