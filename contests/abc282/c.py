N = int(input())
S = list(input())

m = False
for i, c in enumerate(S):
  if S[i] == '"':
    m = not m
  if not m and S[i] == ',':
    S[i] = "."

print(''.join(S))