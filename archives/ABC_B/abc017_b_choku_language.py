T = input()

while len(T) > 0:
  if T[-2:] == "ch":
    T = T[:-2]
  elif T[-1] in ["o", "k", "u"]:
    T = T[:-1]
  else:
    print("NO")
    break
else:
  print("YES")
