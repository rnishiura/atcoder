N, M = tuple(map(int, input().split()))
D = {}
for i in range(M):
  u, v = tuple(map(int, input().split()))
  if not u in D:
    D[u] = [v]
  else:
    D[u].append(v)
  if not v in D:
    D[v] = [u]
  else:
    D[v].append(u)

for d in D.values():
  d.sort()

cnt = 0
for k, v in D.items():
  for i in range(len(v)):
    for j in range(i+1, len(v)):
      if v[j] in D[v[i]] and k < v[i] < v[j]:
        # print(k, v[i], v[j])
        cnt += 1

print(cnt)