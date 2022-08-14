from copy import deepcopy

def main():
  MOD = 200
  N = int(input())
  A = [0] + list(map(int, input().split()))

  PP = [None for i in range(MOD)]
  NP = [None for i in range(MOD)]
  WP = [None for i in range(MOD)]

  PP[0] = []

  # if A[1] % 200 == 0:
  #   print("Yes")
  #   print("1 1")
  #   print("2 1 2")
  #   return

  for i in range(1, N+1):

    # only PP
    for j in range(MOD):
      k = (j+A[i])%MOD
      if PP[j] != None and not PP[k] in [None, []]:
        print("Yes")
        r = PP[j]+[i]
        s = PP[k]
        print(len(r), *r, sep=" ")
        print(len(s), *s, sep=" ")
        return

    # PP to NP
    for j in range(MOD):
      k = (j+A[i])%MOD
      if PP[j] != None:
        if k == 0:
          print("Yes")
          r = [i+1]
          s = PP[j]+[i]+[i+1]
          print(len(r), *r, sep=" ")
          print(len(s), *s, sep=" ")
          return
        else:
          NP[j] = PP[j]
          NP[k] = PP[j]+[i]



    # NP to PP
    PP, NP = deepcopy(NP), deepcopy(WP)
    # print(PP)

  print("No")

main()
