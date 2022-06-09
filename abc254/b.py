N = int(input())

a = [1]
print(1)
for n in range(1, N):
  tmp = [1]
  print(1, end=' ')
  for i in range(0, n-1):
    tmp.append(a[i]+a[i+1])
    print(a[i]+a[i+1], end=' ')
  tmp.append(1)
  print(1)
  a = tmp