N = int(input())
S = input()
T = input()

"""
5
00100
10011

5
00100
00011
11111

5
1100
0001
1111

"""
S = S[::-1]
T = T[::-1]
cnt = 0
for i in range(N):
  if S[i] == '1' and T[i] == '0': 
    cnt -= 1
  if S[i] == '0' and T[i] == '1': 
    cnt += 1
  
# print(cnt)

if cnt % 2 == 1:
  print(-1)
  exit()

if cnt < 0:
  cnt = -cnt
  S, T = T, S

U = ['0' for i in range(N)]

cnt /= 2
for i in range(N):
  if S[i] == '0' and T[i] == '1': 
    U[i] = '1'
    cnt -= 1

  if cnt == 0:
    print(''.join(U[::-1]))
    exit()

print(-1) 