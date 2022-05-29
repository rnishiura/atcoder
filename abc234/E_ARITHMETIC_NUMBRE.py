def searchWithFirst(first, digit, num):
  for diff in range(-9, 10):
    last = first + diff*(digit-1)
    ret = str(first)
    if 0 <= last and last <= 9:
      for i in range(1, digit):
        ret += str(first + diff*i)
        
      ret = int(ret)
      if ret >= num:
        return ret

num   = int(input())
digit = len(str(num))
first = int(str(num)[0])

ret = searchWithFirst(first, digit, num)
if ret != None:
  print(ret)
else:
  print(searchWithFirst(first+1, digit, num))
