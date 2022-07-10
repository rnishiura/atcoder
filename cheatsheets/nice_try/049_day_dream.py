S = input()

token = ["dream","dreamer","erase","eraser"]

def starts(S, w):
  return S[:len(w)] == w

def parse(S):
  if S == "":
    return True

  ret = False
  for t in token:
    if starts(S, t):
      ret = ret or parse(S[len(t):])

  return ret

if parse(S):
  print('YES')
else:
  print('NO')
