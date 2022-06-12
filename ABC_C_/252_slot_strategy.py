N = int(input())
S = []
for i in range(N):
  S.append(input())

max = []
for i in range(10):
  l = {}
  for j in range(N):
    idx = S[j].index(str(i))
    if idx in l:
      l[idx] += 1
    else:
      l[idx] = 1
    
  max.append(0)
  for idx, num in l.items():
    j = idx + 10*(num-1)
    if(max[i] < j):
      max[i] = j

print(min(max))