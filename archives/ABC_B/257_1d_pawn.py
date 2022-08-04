N, K, Q = list(map(int, input().split()))
A = [i for i in list(map(int, input().split()))]
for l in list(map(int, input().split())):
  l -= 1
  if l < K-1 and A[l+1] != A[l]+1 and A[l] < N:
    A[l] += 1
  elif l == K-1 and A[l] < N:
    A[l] += 1

for a in A:
  print(a, end=" ")
print()
  