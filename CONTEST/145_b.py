def f():
  N, A, B = tuple(map(int, input().split()))

  if N < A:
    print(0)
    return
  if A <= B:
    print(N-(A-1))
    return
  if B < A:
    print(min((N-(A-1))%A, B) + (N-(A-1))//A*B)
    return

f()