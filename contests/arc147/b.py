from random import shuffle 

"""
[13, 18, 17, 9, 11, 6, 4, 5, 1, 19, 15, 12, 7, 10, 20, 14, 16, 8, 3, 2]
[1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20]
3 3
[6, 14, 16]
[3, 7, 9]
[('B', 4), ('A', 6), ('B', 8), ('B', 10), ('B', 12), ('A', 14), ('B', 10), ('B', 12), ('B', 14), ('A', 16)]
[13, 18, 17, 6, 11, 4, 9, 19, 1, 10, 15, 20, 7, 14, 5, 16, 12, 8, 3, 2]
Traceback (most recent call last):
  File "/Users/ryota/Desktop/atcoder/playground/b.py", line 86, in <module>
    main()
  File "/Users/ryota/Desktop/atcoder/playground/b.py", line 73, in main
    P[mi-2], P[mi] = P[mi], P[mi-2]
IndexError: list index out of range
"""

def main():
  # N = int(input())
  # P = list(map(int, input().split()))

  N = 20
  P = [i for i in range(1, N+1)]

  shuffle(P)
  print(P)

  PP = P.copy()
  PP.sort()
  print(PP)

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
  print(cnt1, cnt2)
  print(P1)
  print(P2)
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
  print(ret)
  print(P)

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

  print(P)

  print(len(ret))
  # for r in ret:
  #   print(*r)

main()