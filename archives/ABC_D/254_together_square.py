import math
N = int(input())

memo = {}

cnt = N
for i in range(N+1):
  memo[i*i] = True

for i in range(1,N+1):
  for j in range(i+1,N+1):
    if i*j in memo:
      cnt += 2
        
print(cnt)