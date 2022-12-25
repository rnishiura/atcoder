N, L = tuple(map(int, input().split()))
A = tuple(map(int, input().split()))

idx = 1
i = 0
while True:
  if A[i] == 1:
    idx += 2
  if A[i] == 2:
    if idx == L-1:
      idx = L+1
    else:
      idx += 3
  if idx >= L:
    break
  i += 1

for j in range(i+1, N):
  if A[j] == 2:
    print("No")
    exit()

print("Yes")