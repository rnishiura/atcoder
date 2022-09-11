N, M = tuple(map(int, input().split()))
A = [0] + list(map(int, input().split()))
B = [i*A[i] for i in range(N+1)]

T = [0]
for i in range(1, N+1):
  T.append(A[i]+T[i-1])

S = [0]
for i in range(1, N+1):
  S.append(B[i]+S[i-1])

# print(S)
# print(T)

max_val = -400000000000000000000
for i in range(N-M+1):
  val = S[i+M]-S[i]-i*(T[i+M]-T[i])
  # print(val)
  max_val = max(max_val, val)

print(max_val)
