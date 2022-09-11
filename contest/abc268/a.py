A = tuple(map(int, input().split()))
cnt = 0
B = set()
for x in A:
  if not x in B:
    cnt += 1
    B.add(x)
print(cnt)