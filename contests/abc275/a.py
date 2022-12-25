N = int(input())
H = tuple(map(int, input().split()))

max_val = 0 
max_i = 0
for i in range(N):
  if max_val < H[i]:
    max_val = H[i]
    max_i = i

print(max_i + 1)