N = int(input())

XY = []
for i in range(N):
  XY.append(tuple(map(int, input().split())))

S = input()
YY = {}
for i in range(N):
  X, Y = XY[i]
  if not Y in YY:
    YY[Y] = [(X, S[i])]
  else:
    YY[Y].append((X, S[i]))

for XS in YY.values():
  XS.sort()
  # print(XS)
  for i in range(len(XS)-1):
    if XS[i][1]+XS[i+1][1] == "RL":
      print("Yes")
      break 
  else:
    continue
  break
else:
  print("No")
