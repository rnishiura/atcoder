A, B, C = tuple(map(int, input().split()))
A %= 10
l = [A]
i = 2

while True:
  X = (A**i)%10
  if X == A:
    break
  else:
    l.append(X)
  i += 1

i -= 1
B = B%i
UB = [B]
# Cの2進展開
j = 2
while j <= C:
  B *= B
  B %= i
  UB.append(B)
  j *= 2
BC = 1
j = len(UB)-1
while j >= 0:
  if C//(2**j):
    C%=(2**j)
    BC *= UB[j]
    BC %= i
  j -= 1
print(l[(BC+i-1)%i])