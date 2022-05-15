# https://atcoder.jp/contests/abc251/tasks/abc251_c

N = int(input())
A = []
for i in range(N):
  s, t = input().split()
  A.append((s, int(t)))

# # # # # # # # # # # # # # # # # # # # # # # # # 

bools = {}
for i in range(N):
  if not A[i][0] in bools.keys():
    bools[A[i][0]] = (i, A[i][1])

max_i = 0
for i, t in bools.values():
  if t > A[max_i][1]:
    max_i = i

# # # # # # # # # # # # # # # # # # # # # # # # # 

print(max_i + 1)