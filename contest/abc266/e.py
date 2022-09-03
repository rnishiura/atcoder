N = int(input())

E = 0
a = [1, 2, 3, 4, 5, 6]
for i in range(N):
  c = 0
  s = 0
  for aa in a:
    if aa > E:
      s += aa
      c += 1
  E = ((6-c)*E+s)/6

print(E)