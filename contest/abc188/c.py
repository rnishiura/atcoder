N = int(input())
A = [0] + list(map(int, input().split()))
A = tuple(A)

I = [i for i in range(1, 2**N+1)]

for i in range(N-1):
  B = []
  for j in range(0, len(I), 2):
    if A[I[j]] < A[I[j+1]]:
      B.append(I[j+1])
    else:
      B.append(I[j])
  I = B.copy()
  # print(I)

if A[I[0]] < A[I[1]]:
  print(I[0])
else:
  print(I[1])

