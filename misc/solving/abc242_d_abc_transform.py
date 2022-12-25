S = input()
Q = int(input())

for i in range(Q):
  t, k = tuple(map(int, input().split()))
  k = k // (2**t)
  