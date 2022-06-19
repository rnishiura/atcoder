import numpy as np

N = int(input())

arr = np.arange(N*N).reshape(N,N)+1

for i in range(1, N-1):
  for j in range(0, N-1, 2):
    arr[i][j], arr[i][j+1] = arr[i][j+1], arr[i][j]
    # print('wow')

for i in range(N):
  for j in range(N):
    print(arr[i][j], end=" ")
  print()
# print(arr)
# るーる1: 端っこは必ずOK
# ルール2: 同じ行内で並べ替える
# ルール3: 最初、自分より右は大、左は小
# ルール4: 端を含まないN-2数列が満たすべき条件：同じ向きの数に挟まれること