from time import time
loop = 100000

start = time()
A = set()

for i in range(loop):
  A.add(i)

print(time()-start)
start = time()

for i in range(loop):
  if not i in A:
    print("Wow")

print(time()-start)

start = time()
A = list()

for i in range(loop):
  A.append(i)

print(time()-start)
start = time()

for i in range(loop):
  if not i in A:
    print("Wow")

print(time()-start)