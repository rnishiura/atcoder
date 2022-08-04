def main():
  # cdef int i
  N = int(input())
  S = input()
  L = []
  R = []
  for i in range(1, N+1):
    if S[i-1] == "L":
      R.append(i-1)
    if S[i-1] == "R":
      L.append(i-1)

  A = L+[N]+R[::-1]
  for i in range(N+1):
    print(A[i], end=" ")
  print()

main()