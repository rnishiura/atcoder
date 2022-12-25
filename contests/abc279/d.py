from math import sqrt, pow

A, B = tuple(map(int, input().split()))

n = int(pow(2*B/A, -2/3)-1)
print(min(A/sqrt(1+n)+n*B, A/sqrt(n+2)+(n+1)*B))