S = 10000
L = 20000
N, x, y = tuple(map(int, input().split()))
A = tuple(map(int, input().split()))

X = A[0::2]
lX = len(X)

Y = A[1::2]
lY = len(Y)

dpx = [-1 for i in range(L)]
dpx[S+X[0]] = 1
npx = dpx[:]
for p in range(1, lX):
  for i in range(L):
    if dpx[i] == p:
      npx[i+X[p]] = p+1
      npx[i-X[p]] = p+1
  npx, dpx = dpx, npx

dpy = [-1 for i in range(L)]
dpy[S+0] = 0
npy = dpy[:]
for p in range(lY):
  for i in range(L):
    if dpy[i] == p:
      npy[i+Y[p]] = p+1
      npy[i-Y[p]] = p+1
  npy, dpy = dpy, npy

if dpx[S+x] == lX and dpy[S+y] == lY:
  print("Yes")
else:
  print("No")

# print(X)
# print(Y)
# print(lX, dpx[S+x])
# print(lY, dpy[S+y])
# print(dpx[S-10:S+10])
# print(dpy[S-10:S+10])