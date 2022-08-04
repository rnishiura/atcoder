a, b = (int(i)-1 for i in input().split())

line1 = input()
line2 = input()

if a == 0:
  line = line1
else:
  line = line2

if b==0:
  print(line.split()[0])
else:
  print(line.split()[1])