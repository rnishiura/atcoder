import math
x, y, d = tuple(map(int, input().split()))
r = d / 360 * 2 * math.pi
c = math.cos(r)
s = math.sin(r)
print(f"{c*x-s*y} {s*x+c*y}")