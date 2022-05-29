S = input()

a = ['dream', 'dreamer', 'erase', 'eraser']

def startsWith(S, s):
  if S[:len(s)] == s:
    return True
  else:
    return False

flg = True
while flg:
  if startsWith(S, 'dreamer') or startsWith(S, 'eraser'):
    if 