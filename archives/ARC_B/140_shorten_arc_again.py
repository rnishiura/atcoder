n = int( input() )
s = input()

def replace(str, pos, l, str2):
  return str[:pos] + str2 + str[pos+l:]

i = 0
nARC = 0
while True:
  if i >= len(s):
    break
  if s[i:i+3] == "ARC" and s[i-1:i+4] != "AARCC":
    s = replace(s, i, 3, "X")
    nARC += 1
    continue
  i += 1

i = 0
nAARCC = 0
while True:
  if i >= len(s):
    # print("full iter")
    break
  if nAARCC == nARC + 1 + 1:
    # print("short of X")
    break
  if s[i:i+3] == "ARC":
    s = replace(s, i, 3, "R")
    nAARCC += 1
    i = i - 1
    continue
  i += 1


print(nAARCC + nARC)