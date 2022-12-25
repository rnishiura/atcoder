from numpy import inf

def main():
  X, A, D, N = tuple(map(int, input().split()))

  if D == 0:
    print(abs(X-A))
    return

  min_val = inf
  i = (X-A)//D
  for j in range(i-2, i+3):
    j = max(1, j)
    j = min(N, j)
    val = abs(X - (A+D*(j-1)))
    # print(val)
    min_val = min(min_val, val)

  print(min_val)

main()
