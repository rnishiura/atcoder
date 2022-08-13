def main():
  # cdef int i 
  MOD = 1000000000
  # N = int(input())
  a2 = 1
  a1 = 1
  memo = {(1,1)}
  i = 0
  import time
  now = time.time()
  while True:
  # for i in range(N-2):
    a1, a2 = a1+a2, a1
    a1 %= MOD
    # if a1 == 573470001:
    #   print(i)
    #   print(a2)
    if (a2, a1) in memo:
      break
    memo.add((a2, a1))
    i += 1
    if i % 1000000 == 0:
      print(len(memo))
      print(time.time()-now)
      now = time.time()

  print(a1)
  print(a1%MOD)
  print(i)

main()