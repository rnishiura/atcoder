n = 4
d = 10
inf = 10**18

def count_less(arr, x):
  cnt = 0
  for e in arr:
    if e >= x: break
    cnt += 1
  return cnt

dist_1, dist_2 = [], []

for i in range(n):
  x, y = map(float, input().split())
  dist = x**2+y**2
  if dist > d**2: continue
  if i%2 == 0:  dist_1.append(x**2+y**2)
  else:         dist_2.append(x**2+y**2)

dist_1, dist_2 = sorted(dist_1), sorted(dist_2)

min_dist_1, min_dist_2 = inf, inf
if len(dist_1): min_dist_1 = dist_1[0]
if len(dist_2): min_dist_2 = dist_2[0]

if min_dist_1 < min_dist_2:
  print(count_less(dist_1, min_dist_2), 0)
elif min_dist_1 > min_dist_2:
  print(0, count_less(dist_2, min_dist_1))
else:
  print(0, 0)
