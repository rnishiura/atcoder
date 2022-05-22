N = int(input())

mul = 1
tmp = input().split(' ')


for i in range(N):
  mul *= int(tmp[i])
  if mul > 1000000000000000000:
    break


if '0' in tmp:
  print(0)
elif mul > 1000000000000000000:
  print(-1)
else:
  print(mul)

