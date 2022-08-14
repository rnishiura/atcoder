S = input()
A = [0 for i in range(10)]
for c in S:
  A[int(c)] += 1

for i in range(10):
  if A[i] == 0:
    print(i)
    