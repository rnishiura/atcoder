N = int(input())
A = tuple(map(int, input().split()))
B = tuple(map(int, input().split()))

prod = 0
for a, b in zip(A, B):
  prod += a*b

if prod != 0:
  print("No")
else:
  print("Yes")
