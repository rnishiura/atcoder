N = int(input())

P = list(map(int, input().split()))

K = 0
X = []

for i in range(0, 2*N-3, 2):
  if P[i+1] < P[i] < P[i+2] or P[i] < P[i+1] < P[i+2]:
    P[i+1], P[i+2] = P[i+2], P[i+1]
    X.append(i+1+1)
    K += 1
  elif P[i+1] < P[i+2] < P[i] or P[i+2] < P[i+1] < P[i]:
    P[i], P[i+1] = P[i+1], P[i]
    X.append(i+1)
    K += 1

if 2*N >= 3:
  if P[-2] > P[-3] > P[-1] or P[-3] > P[-2] > P[-1]:
    P[-1], P[-2] = P[-2], P[-1]
    X.append(2*N-1)
    K += 1
  elif P[-2] > P[-1] > P[-3] or P[-1] > P[-2] > P[-3]:
    P[-2], P[-3] = P[-3], P[-2]
    X.append(2*N-2)
    K += 1
else:
  if P[0] > P[1]:
    K += 1
    X.append(1)

print(K)
if K>0:
  print(*X, sep=" ")
