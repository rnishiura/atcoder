S1 = input()
S2 = input()

cnt = 0
for c in S1+S2:
  if c == "#":
    cnt += 1

if cnt == 2:
  flg = True
  if S1[0] == S2[1]:
    print("No")
  else:
    print("Yes")
else:
  print("Yes")
  
