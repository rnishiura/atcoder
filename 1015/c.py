N = int(input())
A = tuple(map(int, input().split()))

d = {}
for i in A:
  if not i in d:
    d[i] = 1
  else:
    d[i] += 1

d = tuple(sorted(d.items()))
l = len(d)
# print(d)
f = {}

for i in range(1, l+1):
  f[d[-i][0]] = i-1

# print(f)
res = [0 for i in range(N)]
for i in A:
  res[f[i]] += 1

for i in range(N):
  print(res[i])