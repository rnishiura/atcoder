def main(K):
  K = K-2
  M = 1000000000
  u1, u2, u3, u4 = 1, 1, 1, 0
  U = [(u1, u2, u3, u4)]
  
  i = 0
  while True:
    if not K // 2**i:
      N = i-1
      break
    i += 1

  for i in range(N):
    u1, u2, u3, u4 = u1*u1+u2*u3, u1*u2+u2*u4, u3*u1+u4*u3, u3*u2+u4*u4
    u1, u2, u3, u4 = u1%M, u2%M, u3%M, u4%M
    U.append((u1, u2, u3, u4))
  
  a1, a2 = 1, 1
  i = N
  while K > 0:
    if K // 2**i:
      # print(i, 2**i)
      u1, u2, u3, u4 = U[i]
      a1, a2 = a1*u1+a2*u3, a1*u2+a2*u4
      a1, a2 = a1%M, a2%M
      K %= 2**i
    i -= 1

  # print(a1, a2)
  print(a1)

# def main2(N):
#   # cdef int i 
#   MOD = 1000000000

#   a2 = 1
#   a1 = 1

#   for i in range(N-2):
#     a1, a2 = a1+a2, a1
#     a1 %= MOD

#   print(a1, a2)

N = int(input())
main(N)
# main2(N)