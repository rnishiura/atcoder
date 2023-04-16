s = input()

# img = s.find('img') != -1
img = 'img' in s
# doc = s.find('doc') != -1
doc = 'doc' in s

ans = "other"

if img and doc:
  ans = "presentation"
elif img:
  ans = "image"
elif doc:
  ans = "document"

print(ans)
