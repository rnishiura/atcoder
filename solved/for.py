A = [i for i in range(100)]
for i in range(10**8):
  A[i%100] += 1

print(A[0])