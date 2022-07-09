S = input()

token = ["dream","dreamer","erase","eraser"]

while len(S):
  keepon = False
  for t in token:
    if S[-len(t):] == t:
      S = S[:-len(t)]
      keepon = True
      break
  if not keepon:
    break
  

if S == "":
  print("YES")
else:
  print("NO")