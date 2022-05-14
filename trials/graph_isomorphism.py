# https://atcoder.jp/contests/abc232/tasks/abc232_c

import math

nums = [4, 4, 1, 2, 1, 3, 1, 4, 3, 4, 1, 3, 1, 4, 2, 3, 3, 4]

strings = {}

for i in range(len(nums)):
  if i == 0:
    for i in range(nums[i]):
      strings[nums[i]] = []
  if i == 1:
    continue
  if i // 2 == 0:
    strings[nums[i]] += [nums[i+1]]
  if i // 2 == 1:
    strings[nums[i]] += [nums[i-1]]

  
def fact(list):
  if len(list) == 1:
    return [list, []]
  else:
    return [[list[i]] + fact(list[:i]+list[i+1:]) for i in range(len(list))]

def left(a):
  return a[0][0]

def right(a):
  return a[1:]

def defact(a):
  len = len(a)
  depth = 0
  a = []
  while True:
    b[depth] = a[0][0]