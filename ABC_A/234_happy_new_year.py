N = int(input())

ret = ""
while N > 0:
  ret = str(N%2*2) + ret
  N = N // 2

print(ret)