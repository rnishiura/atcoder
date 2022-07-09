S = input()

token = ["dreameraser", "dreamerase", "dreamer", "dream", "eraser", "erase"]

while len(S):
  i = 0
  for t in token:
    if S[:len(t)] == t:
      S = S[len(t):]
      break
    i += 1
  if i == len(token):
    break

if not len(S):
  print("YES")
else:
  print("NO")
