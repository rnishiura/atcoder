L, R = tuple(map(int, input().split()))
S = input()

S = S[:L-1] + S[L-1:R][::-1] + S[R:]
print(S)