def main():
  V, A, B, C = tuple(map(int, input().split()))

  while True:
    V -= A
    if V < 0:
      print("F")
      return
    V -= B
    if V < 0:
      print("M")
      return
    V -= C
    if V < 0:
      print("T")
      return

main()