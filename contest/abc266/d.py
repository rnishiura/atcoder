N = int(input())

OP = [0 for i in range(6)]
NP = [0 for i in range(6)]

txa = [tuple(map(int, input().split())) for i in range(N)]
lt = txa[-1][0]+1

hist = [(0, 0) for i in range(lt)]

for t, x, a in txa:
  hist[t] = (x, a)

c = 1
for x, a in hist:
  NP[0] = max(OP[0], OP[1])
  NP[5] = max(OP[4], OP[5])
  for i in range(1, 5):
    NP[i] =  max(OP[i-1], OP[i], OP[i+1])
  if x < c:
    NP[x] += a
  OP, NP = NP, OP
  c += 1

print(max(OP))  