from itertools import permutations

def PrimeChecker(num):
  for p in permutations(str(num)):
    n = int(''.join(p))
  
    flg = 1
    for i in range(2, n//2):
      if n % i == 0:
        flg = 0
    if flg == 1:
      return 1

  return 0

PrimeChecker(98)
