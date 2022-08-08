def main():
  N = int(input())

  cnt = 0
  A = tuple(map(int, input().split()))
  A = [a-1 for a in A]
  for i, a in enumerate(A):
    if i == a:
      cnt += 1
      
  cnt2=0
  for i, a in enumerate(A):
    if a != i:
      if A[a] == i: cnt2 += 1
  
  cnt2 = cnt2 // 2

  sum = 0
  if cnt >= 2:
    sum += cnt*(cnt-1)//2

  sum += cnt2
  print(sum)

main()