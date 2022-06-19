N = int(input())

memo = {}

def d(p, q):
  if (p,q) in memo:
    return memo[(p,q)]
  print(f"? {p} {q}")
  memo[(p,q)] = int(input())
  return memo[(p,q)]


def main():
  one_neighbor = []
  two_neighbor = []
  # d23 = d(2,3)
  for i in range(3, N+1):
    ret = d(1,i)
    if ret == 1:
      one_neighbor.append(i)
    
    # if i==3 and abs(d23-ret) == 1:
    #   print("! 1")
    #   return
    if len(two_neighbor) < 2:
      ret = d(2,i)
      if ret == 1:
        two_neighbor.append(i)

  if one_neighbor == [] or two_neighbor == []:
    print("! 1")
    return
  
  if len(two_neighbor) >= 2:
    if d(1,two_neighbor[0]) == 2 and d(1,two_neighbor[1]) == 2:
      print("! 1")
      return 
  else:
    if one_neighbor == []:
      print("! 1")
      return
    else:
      if d(2,one_neighbor[0]) == 2 and d(1,two_neighbor[0]) == 2:
        print("! 1")
        return

  min2n = 1000
  for i in one_neighbor:
    ret = d(2, i)
    min2n = min(min2n, ret)

  print(f"! {min2n+1}")
  return
  # if len(one_neighbor) < len(two_neighbor):
  #   min2n = 100
  #   for i in one_neighbor:
  #     ret = d(2, i)
  #     min2n = min(min2n, ret)

  #   print(f"! {min2n+1}")
  #   return
  # else:
  #   min1n = 100
  #   for i in two_neighbor:
  #     ret = d(1, i)
  #     min1n = min(min1n, ret)

  #   print(f"! {min1n+1}")
  #   return


if __name__ == "__main__":
  main()

# oneもtwoもギリギリまで実行した後、one_neighborが多いケース