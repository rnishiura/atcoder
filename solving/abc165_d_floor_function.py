A, B, N = tuple(map(int, input().split()))

if N < B-1:
  print(A*N//B-A*(N//B))
else:
  print((A*B-A)//B)
