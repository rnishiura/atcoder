memo = {}

def f(t, visited):
  r = False
  visited += {t}
  for t2 in v[t]:
    r |= f(t2, visited2)
  memo[(t2, visited2)] = 

