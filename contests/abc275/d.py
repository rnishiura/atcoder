N = int(input())

memo = {}

def f(n):
  if n in memo:
    return memo[n]
  if n == 0:
    return 1
  else:
    ret = f(n // 2) + f(n // 3)
    memo[n] = ret
    return ret

print(f(N))
