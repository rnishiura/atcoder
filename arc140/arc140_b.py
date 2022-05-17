n = int( input() )
s = input()

def replace(str, pos, l, str2):
  return str[:pos] + str2 + str[pos+l:]

# i = 0
# cnt = 0
# while True:
#   if s[i:i+3] == "ARC":
#     if cnt % 2 == 0:
#       if s[i-1:i+4] == "AARCC":
#         s = replace(s, i-1, 5, "AC")
#         cnt += 2
#       else:
#         s = replace(s, i, 3, "R")
#         cnt += 1
#     else:
#       s = replace(s, i, 3, "AC")
#       cnt += 1
#   i += 1
#   if i >= len(s):
#     break

i = 0
cntARC = 0

while True:
  if i >= len(s):
    break
  if s[i:i+3] == "ARC" and s[i-1:i+4] != "AARCC":
    s = replace(s, i, 3, "X")
    cntARC += 1
    continue
  i += 1

i = 0
cntAARCC = 0
while True:
  print(i, cntARC, cntAARCC, s)
  if i >= len(s):
    print("full iter")
    break
  if s[i:i+5] == "AARCC" and cntAARCC <= cntARC:
    print("replace")
    s = replace(s, i, 5, "ARC")
    cntAARCC += 1
    i = i-1
    continue
  elif s[i:i+3] == "ARC":
    print("no more here")
    s = replace(s, i, 3, "X")
    cntARC += 1
  i += 1

print(cntAARCC + cntARC)

# TODO 場合分けのケースを考える
