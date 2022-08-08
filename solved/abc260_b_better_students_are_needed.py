N, X, Y, Z = tuple(map(int, input().split()))
A = list(map(int, input().split()))
B = list(map(int, input().split()))
D = [A[i]+B[i] for i in range(N)]

C = [False for i in range(N)]
kA = [-i for i in range(N)]
lA = list(zip(A, kA))
lA.sort(reverse=True)
# print(lA)
for i in range(X):
    C[-lA[i][1]] = True
# print(C)

kB = [-i for i in range(N)]
lB = list(zip(B, kB))
lB.sort(reverse=True)
# print(lB)
CB = 0
for i in range(N):
    if CB == Y:
        break
    if not C[-lB[i][1]]:
        C[-lB[i][1]] = True
        CB += 1
# print(C)

kD = [-i for i in range(N)]
lD = list(zip(D, kD))
lD.sort(reverse=True)
CD = 0
for i in range(N):
    if CD == Z:
        break
    if not C[-lD[i][1]]:
        C[-lD[i][1]] = True
        CD += 1

for i in range(N):
    if C[i]:
        print(i+1)
