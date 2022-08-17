def score(S):
  cnt = [0 for i in range(10)]
  for i in range(5):
    cnt[int(S[i])] += 1

  ret = 0
  for i in range(1, 10):
    ret += i * (10 ** cnt[i])

  return ret, cnt

def main():
  K = int(input())
  S = input()[:4]
  T = input()[:4]

  P = 0

  for l in range(1, 10):
    for m in range(1, 10):

      s, sc = score(S + str(l))
      t, tc = score(T + str(m))

      if s > t:
        
        cnt = [K for i in range(10)]
        sum_cnt = 9*K

        for i in range(1, 10):
          cnt[i]  -= sc[i] + tc[i]
          sum_cnt -= sc[i] + tc[i]
        
        cnt[l]  += 1
        cnt[m]  += 1
        sum_cnt += 2
        
        pl = cnt[l] / sum_cnt

        cnt[l]  -= 1
        sum_cnt -= 1

        pl *= cnt[m] / sum_cnt

        P += pl
        
  print(P)

main()