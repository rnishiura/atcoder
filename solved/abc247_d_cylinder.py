from collections import deque

Q = int(input())

deq = deque()
for i in range(Q):
  q = tuple(map(int, input().split()))
  if q[0] == 1:
    deq.append((q[1], q[2]))
    # print(deq)
  else:
    c_val = q[1]
    sum_val = 0
    while c_val > 0:
      x, c = deq.popleft()
      if c > c_val:
        deq.appendleft((x, c-c_val))
        sum_val += x * c_val
        c_val = 0
      else:
        c_val = c_val - c
        sum_val += x * c
    # print(deq)
    print(sum_val)
