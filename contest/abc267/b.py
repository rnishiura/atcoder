S = "X" + input()

def f(i):
  if i==0:
    if "1" in [S[7]]:
      return True
  if i==1:
    if "1" in [S[4]]:
      return True
  if i==2:
    if "1" in [S[2], S[8]]:
      return True
  if i==3:
    if "1" in [S[1], S[5]]:
      return True
  if i==4:
    if "1" in [S[9], S[3]]:
      return True
  if i==5:
    if "1" in [S[6]]:
      return True
  if i==6:
    if "1" in [S[10]]:
      return True
  return False

def main():
  if S[1] == "1":
    print("No")
    return


  for i in range(7):
    for j in range(i+1, 7):
      for k in range(j+1, 7):
        if f(i) and not f(j) and f(k):
          print("Yes")
          return
  print("No")

main()