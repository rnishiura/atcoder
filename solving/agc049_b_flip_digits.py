def main():
  N = int(input())
  S = input()
  T = input()

  TT = [i for i in range(N) if T[i] == '1']
  # print(TT)

  w = False
  i = 0
  M = len(TT)
  b = 0
  cnt = 0
  for j, c in enumerate(S):
    if c == "1":
      if w == True:
        w = False
        cnt += b
      elif i < M and j >= TT[i]:
        cnt += j - TT[i]
        print(j - TT[i])
        i += 1
      else:
        w = True
        b = 0
    b += 1
    print(j, c, w, i)
  if w or i < M:
    print(-1)
  else:
    print(cnt)
main()

"""
13
0110111111111
0100001000100

"""