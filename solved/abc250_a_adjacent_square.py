H, W = tuple(map(int, input().split()))
R, C = tuple(map(int, input().split()))

if H == 1 and W == 1:
  print(0)
elif H == 1:
  if C in [1, W]:
    print(1)
  else:
    print(2)
elif W == 1:
  if R in [1, H]:
    print(1)
  else:
    print(2)
elif R in [1, H] and C in [1, W]:
  print(2)
elif R in [1, H] or C in [1, W]:
  print(3)
else:
  print(4)
