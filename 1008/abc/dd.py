for M in range(1, 10**6+1):
  flg = False
  for i in range(401):
    for j in range(i, 401):
      if i**2 + j**2 == M:
        if flg:
          print(M)
        flg = True
        break