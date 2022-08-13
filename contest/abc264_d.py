S = input()

m = "atcode"
cnt = 0
i = 0
for c in m:
  d = S[i:].find(c)
  cnt += d
  S = list(S)
  # print(S)
  S = S[:i] + [S[i+d]] + S[i:i+d] + S[i+d+1:]
  S = "".join(S)
  i += 1
# print(S)
print(cnt)