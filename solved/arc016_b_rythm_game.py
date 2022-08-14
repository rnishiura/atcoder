cnt = 0
P = "." * 9
for i in range(int(input())):
  C = input()
  for i in range(9):
    if C[i] == "x":
      cnt += 1
    if C[i] == "o" and P[i] != "o":
      cnt += 1
  P = C
print(cnt)