from math import ceil, inf
N = int(input())
X = []
Y = []
P = []

for i in range(N):
  x, y, p = tuple(map(int, input().split()))
  X.append(x)
  Y.append(y) 
  P.append(p)

S = [[ceil((abs(X[i]-X[j]) + abs(Y[i]-Y[j])) / P[i]) if i != j else inf for j in range(N)] for i in range(N)]

for s in S:
  print(*s, sep=" ")

for s in S:
  s = s[:1] + s[2:]
  print(*s, sep=" ")

