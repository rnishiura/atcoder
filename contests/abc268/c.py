N = int(input())
p = tuple(map(int, input().split()))
q = [(p[i]-i)%N for i in range(N)]
# print(q)

C = [0 for i in range(N)]
for qq in q:
  C[qq] += 1
  C[(qq+1)%N] += 1
  C[(qq-1)%N] += 1

print(max(C))