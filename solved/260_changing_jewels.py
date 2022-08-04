N, X, Y = tuple(map(int, input().split()))
R, B = 1, 0
for i in range(N-1):
    B += R*X
    R += B
    B = B*Y
print(B)