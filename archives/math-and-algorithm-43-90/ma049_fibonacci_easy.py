def main():
  # cdef int i 
  MOD = 1000000007
  N = int(input())
  a2 = 1
  a1 = 1

  for i in range(N-2):
    a1, a2 = a1+a2, a1
    a1 %= MOD

  print(a1)

main()