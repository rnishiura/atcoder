from math import sqrt

def isPrime(n):
  if n < 2:
    return False
  for i in range(2, max(int(sqrt(n+1)), n)):
    if n%i == 0:
      return False
  return True

N = int(input())
if N < 2:
  print("Not Prime")
elif isPrime(N):
  print("Prime")
elif N%2 and N%10 != 5 and sum(map(int, tuple(str(N)))) % 3:
    print("Prime")
else:
  print("Not Prime")