def main():
  # cdef int i, j
  N = int(input())

  P = [1 for i in range(N+1)]

  i = 2
  while i <= N:
    j = 1
    while i*j <= N:
      cnt = 0
      n = i*j
      while not n % i:
        n //= i
        cnt += 1 
      # print(i*j, cnt+1)
      P[i*j] *= (cnt+1)
      j += 1
    i += 1
    while i <= N and P[i] > 1:
      i += 1

  SUM = 0
  for i in range(1, N+1):
    SUM += i * P[i]
  print(SUM)

main()