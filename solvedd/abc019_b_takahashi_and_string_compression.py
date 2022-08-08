s = input()
A = ""
idx = 0
l = len(s)
while idx < l:
  A += s[idx]
  cnt = 1
  idx += 1
  while idx < l and s[idx] == A[-1]:
    cnt += 1
    idx += 1
  A += str(cnt)

print(A)
