# https://atcoder.jp/contests/arc141/tasks/arc141_a

T = int(input())
ans = []

for i in range(T):
  N = input()
  cand = []

  for n in range(1, len(N)//2+1):
    # print(n, len(N) % n)
    if len(N) % n != 0:
      continue

    s = N[:n] * (len(N) // n)
    if int(s) > int(N):
      # 繰り下がり分岐
      if int(N[:n]) == 1:
        s = '9' * (len(N) - 1)
      elif int(N[:n]) >= 10 and int(N[:n][0]) == 1 and int(N[:n][1:]) == 0:
        s = '9' * (len(N) - 1)
      else:
        s = str(int(N[:n])-1) * (len(N)//n)

    cand.append(int(s))

  # print(cand)
  print(max(cand))
  # ans.append(max(cand))

# for i in range(T):
#   print(ans[i])
