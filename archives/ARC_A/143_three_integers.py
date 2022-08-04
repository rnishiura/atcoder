def f():
  A = list(map(int, input().split()))
  A.sort()
  a, b, c = A

  # print(a,b,c)

  cnt = 0
  if c - a > b:
    print(-1)
    return 

  cnt = c-b
  a -= cnt
  c = b

  if a < b:
    cnt += b-a
    c, b = a, a

  cnt += a


  # print(a,b,c)
  print(cnt)
  return 
  # least = min(a, b, c)
  # a, b, c = a-least, b-least, c-least

if __name__ == "__main__":
  f()