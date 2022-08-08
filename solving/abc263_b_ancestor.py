N = int(input())
P = tuple(map(int, input().split()))

cnt = 1
idx = N-2
while P[idx] != 1:
  cnt += 1
  idx = P[idx]-2

print(cnt)