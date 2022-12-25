s = input()

i = 0
cnt = 0
while i < len(s):
  if i+1 < len(s) and s[i] == s[i+1] == '0':
    i += 2
  else:
    i += 1
  cnt += 1

print(cnt)