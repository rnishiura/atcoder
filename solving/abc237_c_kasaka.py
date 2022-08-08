S = input()
N = len(S)
la, ra = 0, 0

while la < N and S[la] == "a":
  la += 1


while ra < N and S[N-1-ra] == "a":
  ra += 1

# print(la, ra)
if la == N:
  print("Yes")
elif la > ra:
  print("No")
else:
  S = S[la:N-ra]
  N = len(S)
  for i in range(N // 2 + 1):
    if S[i] != S[N-1-i]:
      print("No")
      break
  else:
    print("Yes")
