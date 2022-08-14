L = ";"
R = ")"
N = int(input())

def falling_snow(s):
  i = N-1
  c = 1
  while i != -1:
    i = s.rfind(L, 0, i)
    if i < N - 2*c:
      s = list(s)
      for j in range(i, N):
        s[j] = R
      for j in range(i+1, i+1+c):
        s[j] = L
      return "".join(s)
    else:
      c += 1
  return -1

def main():
  if N % 2:
    return 

  s = L * (N//2) + R * (N//2)
  while s != -1:
    print(s)
    s = falling_snow(s)

main()