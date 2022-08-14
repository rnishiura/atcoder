from itertools import product

def h2i(h):
  ret = []
  for i in range(len(h)):
    if h[i] == 1:
      ret.append(i)
  return ret

def main():
  cdef int i, j
  H1, W1 = tuple(map(int, input().split()))
  A = []
  for i in range(H1):
    A.append(tuple(map(int, input().split())))

  H2, W2 = tuple(map(int, input().split()))
  B = []
  for i in range(H2):
    B.append(tuple(map(int, input().split())))

  A = tuple(A)
  B = tuple(B)
  # print(A)
  # print(B)
  # print(B == B.copy())

  for h in product([0, 1], repeat=H1):
    h = h2i(h)
    if len(h) != H2:
      continue
    for w in product([0, 1], repeat=W1):
      w = h2i(w)
      if len(w) != W2:
        continue
      flg = True
      for i in range(H2):
        for j in range(W2):
          if A[h[i]][w[j]] != B[i][j]:
            flg = False
      if(flg):
        print("Yes")
        break
    else:
      continue
    break
  else:
    print("No")

main()