# cdef int i, j
MAX = 100000
N = int(input())
T = tuple(map(int, input().split()))

O  = [None for i in range(MAX+1)]
NO = [None for i in range(MAX+1)]
O[0] = 0

for i in range(N):
  for j in range(MAX+1):
    if O[j] != None:
      NO[j] = O[j]+T[i]
    if j >= T[i] and O[j-T[i]] != None:
      if O[j] != None:
        NO[j] = min(O[j]+T[i], O[j-T[i]])
      else:
        NO[j] = O[j-T[i]]

  O, NO = NO, O

m = MAX
for j in range(MAX+1):
  if O[j] != None:
    m = min(m, max(j, O[j]))

print(m)