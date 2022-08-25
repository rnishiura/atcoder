N = int(input())

A = []
for i in range(N):
  A.append(tuple(map(int, input().split())))

A = sorted(A, key=lambda x: x[1])

time = 0
for a, b in A:
  time += a
  if time > b:
    print("No")
    break
else:
  print("Yes")
