N = int(input())
A = tuple(map(int, input().split()))
B = tuple(map(int, input().split()))
C = sorted(list(zip(A, B)))

# print(A)
# print(B)
print(list(zip(*C)))