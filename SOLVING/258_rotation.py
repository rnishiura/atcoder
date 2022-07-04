N, Q = list(map(int, input().split()))
S = input()

idx = N - 1
for i in range(Q):
  q, x = list(map(int, input().split()))
  if q == 1:
    idx = (idx-x) % N
  if q == 2:
    print(S[(idx+x)%N])
