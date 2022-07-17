ones = ["zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"]
tens = ["", "ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eightty", "ninety"]
teen = ["ten", "eleven", "twelve", "thirteen", "forteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"]
thousands = ["", "thousand", "million", "billion"]

def under_k(n):
  ret = ""
  if n >= 100:
    ret += ones[n//100] + " hundred "
  if n%100 >= 20:
    ret += tens[n//10%10] + " "
  if 19 >= n%100 >= 10:
    ret += teen[n%100-10]
  elif n%10 > 0:
    ret += ones[n%10]
  return ret

def above_k(n):
  if n==0:
    return "zero"

  ret = ""
  i = 0
  while (n > 0):
    if n%1000 != 0:
      ret = under_k(n%1000) + " " + thousands[i] + " " +  ret
    i += 1
    n //= 1000
  return ret

def under_point(n):
  ret = "point "
  for nn in n:
    ret += ones[int(nn)] + " "
  return ret

def whole(n):
  if n == "":
    return "-1"
  n = n.split('.')
  if n[0][0] == "0" and len(n[0]) > 1:
    return "-1"
  if len(n) > 2:
    return "-1"
  for nn in n:
    if not nn.isdigit():
      return "-1"
  # else:
  if len(n) == 2:
    return above_k(int(n[0])) + " " + under_point(n[1])
  if len(n) == 1:
    return above_k(int(n[0]))



print(" ".join(whole(input()).split()).capitalize())