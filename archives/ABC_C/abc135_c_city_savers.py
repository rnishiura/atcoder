N = int(input())
A = tuple(map(int, input().split()))
B = tuple(map(int, input().split()))

C  = 0
cnt = 0
for i in range(N):
  if C >= A[i]:
    cnt += A[i]
    C = B[i]
  elif B[i]+C >= A[i]:
    cnt += A[i]
    C = B[i]+C - A[i]
  else:
    cnt += B[i]+C
    C = 0

cnt += min(C, A[N])
print(cnt)
