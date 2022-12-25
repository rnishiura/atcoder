N = int(input())
A = list(map(int, input().split()))

min2=10**18
max2=0
min3=10**18
max3=0

t = 0
for i in range(N):
  m2 = 0
  while A[i] % 2 == 0:
    A[i] /= 2
    m2 += 1
  min2 = min(m2, min2)
  max2 += m2

  m3 = 0
  while A[i] % 3 == 0:
    A[i] /= 3
    m3 += 1
  min3 = min(m3, min3)
  max3 += m3
  if i > 0:
    if A[i] != t:
      print(-1)
      exit()
  t = A[i]

print(max3 - N*min3 + max2 - N*min2)
