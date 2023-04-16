MOD = 998244353
n = int(input())

a = [[0]*i + list(map(int, input().split())) for i in range(n)]

# print(a)

def inv(i):
  if i==1:
    return 1
  return MOD - inv(MOD%i) * (MOD//i) % MOD
# 2-1 elim
for i in range(n):
  for j in range(i, n):
    if a[i][j] == 2:
      for k in range(i+1):
        for l in range(j, n):
          if a[k][l] == 1:
            print(0)
            exit()
          a[k][l] = 0
      a[i][j] = 2

# 1 left
for i in range(n):
  for j in range(i, n):
    if a[i][j] == 1:
      for k in range(i, j):
        a[i][k] = 1

print(a)
id = [0] * n
r = 2
if a[0][0] == 2:
  r = 0
for j in range(1, n):
  if a[j][j] == 2:
    r = 0
  s = 10**18
  t = -1
  for i in range(j):
    if a[i][j] == 1:
      s = min(s, i)
    if a[i][j] == 2:
      t = i
  if s != 10**18:
    id[j] = id[i]
  else:
    id[j] = id[j-1]+1
    r *= 2
    r %= MOD
  if t != -1:
    m = 1
    for _ in range(id[j]-id[t]+1):
      r *= inv(2)
      r %= MOD
      m *= 2
      m %= MOD
    r *= m-2
    r %= MOD
  
# print(inv(2))
print(id)
print(r)


"""
4
1 0 2 0
  1 0 0
    1 0 
      1

"""