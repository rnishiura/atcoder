N = int(input())
S = input()

C = {}
for s in S:
  if s in C:
    C[s] += 1
  else:
    C[s] = 1

MOD = 1000000007
r = 1
for c in C.values():
  r = r * (c+1)
  r %= MOD

print(r-1)