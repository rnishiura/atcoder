cnt = 0

def min_cost(i, h, memo):
  global cnt
  # print(f"{cnt}, {i}, {memo}")
  cnt += 1
  if i in memo:
    # print("memo")
    return memo[i]
  
  if i==1:
    return abs(h[1]-h[0])
  elif i==0:
    return 0
  else:
    # print("no memo")
    d1 = abs(h[i]-h[i-1]) + min_cost((i-1), h, memo)
    d2 = abs(h[i]-h[i-2]) + min_cost((i-2), h, memo)
    ret = min(d1, d2)
    memo[i] = ret
    return ret

def main():
  import sys
  sys.setrecursionlimit(2000000000)
  # N = int(input())
  # h = list(map(int, input().split()))
  N = int(10e4)
  import numpy as np
  h = [np.random.randint(0, 10e4+1) for i in range(N)]
  memo = {}
  print(min_cost(N-1, h, memo))
  global cnt
  # print(h)
  # print(cnt)
  # print(memo)

if __name__ == "__main__":
  main()