h1, h2, h3, w1, w2, w3 = map(int, input().split())

cnt = 0
a = min(h1, w1) - 2
for a11 in range(1,a+1):
  for a12 in range(1,(h1-a11-1)+1):
    for a21 in range(1,(w1-a11-1)+1):
      b = max(h2-a12, w2-a21) - 1
      for a22 in range(1,b+1):
        a13 = h1-a11-a12
        a23 = h2-a21-a22
        a31 = w1-a11-a21
        a32 = w2-a12-a22
        if a32 < 1 or a23 < 1:
          continue
        if h3-a31-a32 == w3-a13-a23:
          a33 = w3-a13-a23
          if a33 < 1:
            continue
          cnt += 1
          # print([[a11,a12,a13],[a21,a22,a23],[a31,a32,a33]])

print(cnt)