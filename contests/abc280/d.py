from math import sqrt
K = int(input())

r = 1
p = 1
k = sqrt(K)

while p <= k:
  print(p)
  # if r % K == 0:
  #   print(p)
  #   break
  # p += 1
  # r *= p
else:
  print(K)
