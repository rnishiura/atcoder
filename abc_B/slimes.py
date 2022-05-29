import math
A, B, K = [int(i) for i in input().split(' ')]

ret = math.log(B/A, K)
if math.isclose(ret, math.floor(ret)):
  ret = math.floor(ret)
else:
  ret = math.ceil(ret)

print( ret )
