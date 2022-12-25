def isUpper(c):
  if ord("A") <= ord(c) <= ord("Z"):
    return True
  else:
    return False

S = input()
if len(S) != 8:
  print("No")
  exit()

if (not isUpper(S[0])) or (not isUpper(S[7])):
  print("No")
  exit()

if S[1:7].isdigit() and 100000 <= int(S[1:7]) <= 999999:
  print("Yes")
  exit()

print("No")