def c(a, c, b):
  return b[1]*(c[0]-a[0])-b[0]*(c[1]-a[1])-c[0]*a[1]+a[0]*c[1]

xy = [tuple(map(int, input().split())) for i in range(4)]
for i in range(2):
  if c(xy[i], xy[(i+2)%4], xy[(i+1)%4])*c(xy[i], xy[(i+2)%4], xy[(i+3)%4]) >= 0:
    print('No')
    break
else:
  print("Yes")