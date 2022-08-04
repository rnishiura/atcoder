def f(x, a):
  return (a[0][0]-a[1][0])*(x[1]-a[0][1]) - (a[0][1]-a[1][1])*(x[0]-a[0][0])

def dist2(x1, x2):
  return (x1[0]-x2[0])**2 + (x1[1]-x2[1])**2

def g(x, a):
  prod = (a[0][0]-x[0])*(a[1][0]-x[0])+(a[0][1]-x[1])*(a[1][1]-x[1])
  # print(prod)
  # print(dist2(x, a[0])*dist2(x, a[1]))
  ret = prod < 0 and prod**2 == dist2(x, a[0])*dist2(x, a[1])
  # print(a, x, ret)
  return ret or x == a[0] or x == a[1]

def main():
  x = tuple([tuple(map(int, input().split())) for i in range(4)])

  for i in range(0, 4, 2):
    a = x[i:i+2]
    for j in range(2):
      if g(x[2-i+j], a):
        print("Yes")
        return
    
  for i in range(0, 4, 2):
    a = x[i:i+2]
    if f(x[2-i+0], a) * f(x[2-i+1], a) >= 0:
      break
  else:
    print("Yes")
    return
  print("No")


main()