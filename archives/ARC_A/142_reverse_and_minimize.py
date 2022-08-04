N, K = map(int, input().split())

cnt = 0
for i in range(13):
  if N >= int(str(K)+'0'*i):
    cnt+=1
  if N >= int(str(K)[::-1]+'0'*i) and (str(K) != str(K)[::-1]):
    cnt+=1

if str(K)[-1] == '0' and N >= K:
  cnt = 1

if int(str(K)[::-1]) < K:
  cnt = 0 

print(cnt)