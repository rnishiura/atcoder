def gcd(a, b):
  a, b = max(a, b), min(a, b)
  if not a%b:
    return b
  else:
    return gcd(b, a%b)

def lcm(a, b):
  return a * b // gcd(a, b)

def main():
  N, M = tuple(map(int, input().split()))
  S = input()
  T = input()

  L = lcm(N, M)

  for i in range(N):
    if not (i*L//N)%(L//M) and S[i] != T[(i*L//N)//(L//M)]:
      print(-1)
      return
  for i in range(M):
    if not (i*L//M)%(L//N) and T[i] != S[(i*L//M)//(L//N)]:
      print(-1)
      return

  print(L)

main()