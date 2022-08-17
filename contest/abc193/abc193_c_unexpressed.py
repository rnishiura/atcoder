from math import sqrt

N = int(input())

cnt = 0
good = [True for i in range(int(sqrt(N))+1)]
for i in range(2, int(sqrt(N))+1):
  if not good[i]:
    continue
  j = 2
  while i**j <= sqrt(N):
    good[i**j] = False
    j+=1
  while i**j <= N:
    j+=1
    
  j-=1
  cnt += j - 1

print(N - cnt)
