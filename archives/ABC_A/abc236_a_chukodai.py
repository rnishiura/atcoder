S = input()
a, b = tuple(map(int, input().split()))
a = a-1
b = b-1
for i in range(len(S)):
  if i == a:
    print(S[b], end="")
  elif i == b:
    print(S[a], end="")
  else:
    print(S[i], end="")
print()