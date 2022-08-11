def conv(s, MODE=1):
  s = list(map(int, tuple(s)))
  l = len(s)
  # print(l)

  # 2 to pre -2
  for i in range(l):
    c = s[i]
    if c == 1 and i % 2 == MODE:
      # print(i+1)
      if i+1 < l:
        s[i+1] += 1
      else:
        s.append(1)
  
  # print("".join(map(str, s)))

  # pre -2 to complete -2
  s += [0, 0]
  l = len(s)
  for i in range(l):
    c = s[i]
    if c == 2 or c == 3:
      if s[i+1] > 0:
        s[i+1] -= 1
      else:
        s[i+1] += 1
        s[i+2] += 1
    if c == 2:
      s[i] = 0
    if c == 3:
      s[i] = 1
    if c == 4:
      s[i] = 0
      s[i+2] += 1

  return "".join(map(str, s))

def m2d(s):
  ret = 0
  s = map(int, tuple(s))
  for i, c in enumerate(s):
    ret += (-2)**i * c
  return ret

def d2p(n):
  top = 0
  m = n
  while m >= 2**top:
    top += 1

  s = []
  for i in range(top):
    b = 2**(top-1-i)
    s = [n//b] + s
    n %= b
  return "".join(map(str, s))

def main():
  MODE = 1
  s = int(input())
  if s < 0:
    MODE = 0
    s = -s
  s = d2p(s)
  # print(s)
  s = conv(s, MODE)
  e = s[::-1]
  e = e[e.find("1"):]
  print(e)
  # print(m2d(s))

main()

"""
1 0
2 1 2
3 0 1 2
4 2
"""