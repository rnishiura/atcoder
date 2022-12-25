N = int(input())
A = tuple(map(int, input().split()))

C4 = 0
C2 = 0

for i in A:
  if i % 4 == 0:
    C4 += 1
  elif i % 2 == 0:
    C2 += 1

if C2 > 0:
  if C4 >= N-C4-C2:
    print("Yes")
  else:
    print("No")
else:
  if C4 >= N-C4-1:
    print("Yes")
  else:
    print("No")
  