def gcd(a, b):
  a, b = max(a, b), min(a, b)
  if not a%b:
    return b
  else:
    return gcd(b, a%b)

def main():
  N, X = tuple(map(int, input().split()))
  x = tuple(map(lambda x: abs(int(x)-X), input().split()))
  if N == 1:
    print(x[0])
    return

  g = gcd(x[0], x[1])
  for i in range(2, N):
    g = gcd(g, x[i])

  print(g)
  return

main()