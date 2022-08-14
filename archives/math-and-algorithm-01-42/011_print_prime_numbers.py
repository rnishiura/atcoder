N = int(input())

P = [True for i in range(N+1)]

i = 2
while i <= N//2:
  j = 2
  while i*j <= N:
    P[i*j] = False
    j += 1
  i += 1
  while P[i] == False:
    i += 1

for i in range(2, N+1):
  if P[i]:
    print(i, end=" ")

print()
