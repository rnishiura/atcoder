def room_member(M, R):
  if R > 1:
    ret = []
    for i in range(M+1):
      for r in room_member(i, R-1):
        ret.append([M-i] + r)
    return ret
  elif R == 1:
    return [[M]]
  else:
    return [[]]


print(len(room_member(16, 8)))
