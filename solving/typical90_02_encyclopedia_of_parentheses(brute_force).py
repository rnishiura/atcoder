from itertools import product

L = "("
R = ")"
N = int(input())

def valid(c):
  lc = 0
  rc = 0
  for d in c:
    if d == L:
      lc += 1
    else:
      rc += 1
    if rc > lc:
      return False
  if rc == lc:
    return True
  else:
    return False

def main():
  if N % 2:
    return 

  s = []
  for c in product([L, R], repeat=N):
    if valid(c):
      s.append(c)

  s.sort()
  for c in s:
    print("".join(c))
  # print(len(s))

main()