w = ["and", "not", "that", "the", "you"]

n = int(input())

for a in input().split():
  if a in w:
    print("Yes")
    exit()

print("No")