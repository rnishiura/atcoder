a = [int(n) for n in input().split()] 
n, s = a[0], a[1]

def sum_of(k):
    return int( (k+1) * k/2 )

def eval():
    if s >= 2*n:
        return n*n
    elif s >= n:
        return n*n - sum_of(2*n-s)
    else:
        return sum_of(s-1)

print( eval() )