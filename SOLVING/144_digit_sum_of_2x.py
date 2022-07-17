N = int(input())

x = '4' * (N//4)
if N%4:
  x = str(N%4) + x

print(2*N)
print(x)
