def extract(DP, sweights):
  ret = []
  idx = 0
  for w in sweights:
    if idx == len(DP) or w > DP[idx][0]:
      ret.append((w, DP[idx-1][1]))
    elif w == DP[idx][0]:
      ret.append(DP[idx])
      idx += 1
    else:
      raise ValueError()
  return ret

N, W = map(int, input().split())

DP = [(W+1, 0)] # 初期値

for i in range(N):
  v, w = map(int, input().split())
  if w > W:
    continue

  # generate mater
  mater = DP

  # generate pater
  pater = []
  for bw, bv in DP[::-1]:
    if bw+w <= W:
      pater.append((bw+w, bv+v))
    else:
      pater.append((W+1, bv+v))
      break
  pater = pater[::-1]
  pater.append((w, 0))

  # generate shared weights
  sweights = {}
  for w, _ in pater:
    sweights[w] = 1
  for w, _ in DP:
    sweights[w] = 1
  sweights = list(sweights)
  sweights.sort(reverse=True)

  # extract both with shared weights
  mater = extract(mater, sweights)
  pater = extract(pater, sweights)

  # max alive operation
  baby = []
  for i in range(len(sweights)):
    baby.append((sweights[i], max(mater[i][1], pater[i][1])))

  # shrink and renew DP
  DP = [baby[0]]
  for idx in range(1, len(baby)):
    if baby[idx][1] < baby[idx-1][1]:
      DP.append(baby[idx])
    elif baby[idx][1] == baby[idx-1][1]:
      pass
    else:
      raise ValueError()
      
print(DP[0][1])


"""
30 499887702
128990795 137274936
575374246 989051853
471048785 85168425
640066776 856699603
819841327 611065509
704171581 22345022
536108301 678298936
119980848 616908153
117241527 28801762
325850062 478675378
623319578 706900574
998395208 738510039
475707585 135746508
863910036 599020879
340559411 738084616
122579234 545330137
696368935 86797589
665665204 592749599
958833732 401229830
371084424 523386474
463433600 5310725
210508742 907821957
685281136 565237085
619500108 730556272
88215377 310581512
558193168 136966252
475268130 132739489
303022740 12425915
122379996 137199296
304092766 23505143

"""