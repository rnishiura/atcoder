N = int(input())

if (N-2) % 4 == 0:
  print(N)
else:
  print((N-2)//4*4+6)