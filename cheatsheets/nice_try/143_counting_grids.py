from scipy.special import comb
from operator import mul
from functools import reduce
import sys
sys.setrecursionlimit(100000000)
nCr = {}
def cmb(n, r):
    if r == 0 or r == n: return 1
    if r == 1: return n
    if (n,r) in nCr: return nCr[(n,r)]
    nCr[(n,r)] = cmb(n-1,r) + cmb(n-1,r-1)
    return nCr[(n,r)]

# a = cmb(n, r)
N = int(input())

# a = cmb(n,r,mod)
def m(a, b):
  return ((a%998244353) * (b%998244353)) %998244353

def fact(N):
  ret = 1
  for i in range(1, 1+N):
    ret = m(ret, i)
  return ret

A = fact(N**2)
fn = fact(N)
B = m(fn, fn)
C = 0
D = fact(N**2-2*N+1)
memo = {}
for K in range(N, 1+N**2-N+1):

  # print('"', K)
  # if not (K-1, N-1) in memo:
  #   tmp1 = comb(K-1, N-1, exact=True)
  # else:
  #   tmp1 = memo[(K-1, N-1)]
  # if not (N**2-K, N-1) in memo:
  #   tmp2 = comb(N**2-K, N-1, exact=True)
  # else:
  #   tmp2 = memo[(N**2-K, N-1)]
  # tmp1 = comb(K-1, N-1, exact=True)
  # tmp2 = comb(N**2-K, N-1, exact=True)
  
  tmp1 = cmb(K-1, N-1)
  tmp2 = cmb(N**2-K, N-1)
  # tmp1 = m(tmp1, fact(N-1))
  # tmp2 = m(tmp2, fact(N-1))
  # print(tmp1)
  # print(tmp2)
  # print(tmp1 * tmp2)
  C += m(tmp1, tmp2)
  C %= 998244353
  # C = m(C, D)

# print(A, B, C)
print(A, B, C, D)
print((A-m(m(B, C), D))%998244353)
# print((A-m(N**2, C))%998244353)

# (N2!)-N!*N!*sum(K-1(C)2+(N-K)C2)|K(N:N2-N+1) % 998244353

"""
1
23



i行を最小値aiとそれ以外に分ける
require: aiは列の中で最大でない（最大値b!=aが存在する）
その数のN!*N!倍ある
1
2
345
余事象で・・・
K(3:7):(N:N2-N+1)
sum(K-1(C)2 + (N-K)C2) 
(N2!)-N!*N!*sum(K-1(C)2+(N-K)C2)|K(N:N2-N+1) % 998244353
5%3


123
456
789

14
23


"""