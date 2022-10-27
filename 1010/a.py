# from math import sqrt
# N = int(input())

# for i in range(N):
#   A, B = map(int, input().split())
#   min_val = 10**18
#   min_X = 0
#   min_Y = 0
#   for k in list(range(1, int(sqrt(B-1))+1)) + [B]:
#     X = max(0, (B-1) // k + 1 - A)
#     Y = max(0, k*(X+A)-B)
#     if min_val > X+Y:
#       min_val = X+Y
#       min_X = X
#       min_Y = Y
    
#   print(min_val, min_X, min_Y)

A, B = 4394, 993298361
for X in range(66):
  Y = 65-X
  if (Y+B) % (X+A) == 0:
    print(X, Y)
  
# 25 = (B-1) // k + 1 - A
# (B - 1) // 1 