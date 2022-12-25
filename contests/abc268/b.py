S = input()
T = input()
if len(S) <= len(T) and S == T[:len(S)]:
  print("Yes")
else:
  print("No") 