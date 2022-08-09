N, M = tuple(map(int, input().split()))

m = [[0 for j in range(N)] for i in range(N)]
for i in range(M):
  u, v = tuple(map(int, input().split()))
  u -= 1
  v -= 1
  m[u][v] = 1
  m[v][u] = 1

print(m)



# old = set()
# arc = {1}
# new = set()
# for i in range(N):
#   for j in arc:
#     new = new.union(con[j]) 
#     # print(new)
#   old = old.union(arc)
#   arc = new.copy()

# old.union(arc)
# if len(old) == N:
#   print("The graph is connected.")
# else:
#   print("The graph is not connected.")
