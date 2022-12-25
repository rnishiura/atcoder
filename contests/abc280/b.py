N = int(input())
S = [0] + list(map(int, input().split()))

for i in range(N):
  print(S[i+1]-S[i], end=" ")

print()