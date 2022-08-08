L1, R1, L2, R2 = tuple(map(int, input().split()))
if R2 <= L1:
  print(0)
elif L2 <= L1 and R2 <= R1:
  print(R2 - L1)
elif L2 <= L1 and R2 >= R1:
  print(R1 - L1)
elif L2 >= L1 and R2 <= R1:
  print(R2 - L2)
elif L2 >= L1 and L2 <= R1 and R2 >= R1:
  print(R1 - L2)
elif L2 >= R1:
  print(0)