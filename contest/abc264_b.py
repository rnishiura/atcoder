# from math import abs
R, C = tuple(map(int, input().split()))

if abs(R-8) % 2 == 0 and abs(C-8) <= abs(R-8):
  print("white")
elif abs(C-8) % 2 == 0 and abs(R-8) <= abs(C-8):
  print("white")
else:
  print("black")