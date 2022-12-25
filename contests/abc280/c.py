S = input()
T = input()

l = len(S)
for i in range(l):
  if S[i] != T[i]:
    print(i+1)
    exit()

print(l+1)