N, M = tuple(map(int, input().split()))
A = tuple(map(int, input().split()))

L = 0 
R = N

for i in range(1, M+1):
  while True:
    M = (L+R) // 2
    if A[M] + i*M < 0:
      L = M
    else:
      R = M

    if L+1 >= R:
      print(M, A[M] + i*M)
      break