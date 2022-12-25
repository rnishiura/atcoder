def gcd(a, b):
  a, b = max(a, b), min(a, b)
  if not a%b:
    return b
  else:
    return gcd(b, a%b)

def lcm(a, b):
  g = gcd(a, b)
  return g * (a//g) * (b//g)

N, A, B = tuple(map(int, input().split()))
C = lcm(A, B)
P = (N+1) * N // 2
Q = (A * (N // A) + A) * (N // A) // 2
R = (B * (N // B) + B) * (N // B) // 2
S = (C * (N // C) + C) * (N // C) // 2
print(P - Q - R + S)