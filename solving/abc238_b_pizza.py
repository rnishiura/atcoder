N = int(input())
A = tuple(map(int, input().split()))

arg = 0
B = {0}
for a in A:
  arg = (arg+a) % 360
  B.add(arg)

max_arg = 0
B = list(B)
B.sort()
for i in range(len(B)-1):
  max_arg = max(max_arg, B[i+1]-B[i])
max_arg = max(max_arg, 360-B[-1])

print(max_arg)
