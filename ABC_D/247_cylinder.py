N = int(input())

DEBUG = True

def debug(s):
  if DEBUG == True:
    print(s)

def queueStatus(queue):
  tmp = queue
  while True:
    debug(tmp.get())
    if tmp.next() == None:
      break
    else:
      tmp = tmp.next()


class Queue:
  def __init__(self, x, c):
    self.__x = x
    self.__c = c
    self.__next = None

  def set(self, c):
    self.__c = c
    
  def push(self, next):
    self.__next = next

  def next(self):
    if self.__next == None:
      debug("Warning: invalid queue!")
    return self.__next

  def pop(self):
    pass

  def get(self):
    return (self.__x, self.__c)

last = Queue(0, 0)
first = last

for i in range(N):
  query = [int(i) for i in input().split(' ')]
  
  if query[0] == 1:
    next = Queue(query[1], query[2])
    last.push(next)
    last = last.next()

  if query[0] == 2:
    s = 0
    remained = query[1]
    while remained > 0:
      x, c = first.get()
      if c > remained:
        s += x * remained
        first.set(c - remained)
        remained = 0
      else:
        s += x * c
        remained -= c
        first = first.next()
    print(s)
    
  queueStatus(first)

