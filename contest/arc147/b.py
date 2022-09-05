def main():
  N = int(input())
  P = list(map(int, input().split()))

  PP = P.copy()
  PP.sort()
  # print(PP)

  cnt1 = 0
  cnt2 = 0
  # PPP = {}
  P1 = []
  P2 = []
  for i in range(N):
    j = PP.index(P[i])
    if i%2 == 0 and j%2 == 1:
      cnt1 += 1
      # PPP[P[i]] = (i, 1)
      P1.append(i)
    elif i%2 == 1 and j%2 == 0:
      cnt2 += 1
      # PPP[P[i]] = (i, 2)
      P2.append(i)

  if cnt1 != cnt2:
    print(0)
    return
  # print(cnt1, cnt2)
  # print(P1)
  # print(P2)
  # print(PPP)

  P1.sort()
  P2.sort()

  ret = []

  for i in range(cnt1):
    while P1[i]+1 != P2[i] and P1[i]-1 != P2[i]:
      if P1[i] < P2[i]:
        # print("B", P2[i]-2+1)
        ret.append(("B", P2[i]-2+1))
        P[P2[i]], P[P2[i]-2] = P[P2[i]-2], P[P2[i]]
        P2[i] -= 2
      elif P1[i] > P2[i]: 
        # print("B", P2[i]+1)
        ret.append(("B", P2[i]+1))
        P[P2[i]], P[P2[i]+2] = P[P2[i]+2], P[P2[i]]
        P2[i] += 2
    # print("A", P1[i]+1)
    ret.append(("A", min(P1[i], P2[i])+1))
    P[P1[i]], P[P2[i]] = P[P2[i]], P[P1[i]]

  # print(1)
  # print("A 0")

  for i in range(N):
    # print(i)
    mi = i+P[i:].index(min(P[i:]))
    while mi != i:
      # print("B", mi-2+1)
      ret.append(("B", mi-2+1))
      P[mi-2], P[mi] = P[mi], P[mi-2]
      mi -= 2


  # print(1)
  # print("A 0")

  print(len(ret))
  for r in ret:
    print(*r)

main()