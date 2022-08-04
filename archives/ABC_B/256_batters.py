N = int(input())
A = map(int, input().split())

P = 0
base = [False,False,False,False]

for a in A:
  base[0] = True
  new_base = [False,False,False,False]
  for i in range(4):
    if base[i]:
      if i+a < 4:
        new_base[i+a] = True
      else:
        P += 1
  base = new_base

print(P)