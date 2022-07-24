from math import cos, sin, pi
N = int(input())
x0, y0 = tuple(map(int, input().split()))
xx, yy = tuple(map(int, input().split()))
xc, yc = (x0+xx)/2, (y0+yy)/2
c, s = cos(2*pi/N), sin(2*pi/N)
x, y = x0-xc, y0-yc
x1, y1 = xc + x*c - y*s, yc + x*s + y*c
print(f"{x1} {y1}")