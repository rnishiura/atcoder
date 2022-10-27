A = [i*2 for i in range(50)]

def bs(n, A):
  L = 0
  R = len(A)
  while True:
    M = (L+R)//2
    if A[M] < n:
      L = M
    else:
      R = M

    if L+1 >= R:
      print(L, R)
      print(A[L], A[R])
      break

bs(-1, A)