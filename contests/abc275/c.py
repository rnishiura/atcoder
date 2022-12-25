S = [input() for i in range(9)]
S = [[(S[i][j] == "#") for j in range(9)] for i in range(9)]

cnt = 0

for i in range(9):
  for j in range(9):
    for k in range(9):
      for l in range(9):
        if i == k and j == l: 
          continue
        if S[i][j] and S[k][l]:
          p, q = i+(l-j), j-(k-i)
          if p in range(9) and q in range(9) and p+(k-i) in range(9) and q+(l-j) in range(9) and S[p][q] and S[p+(k-i)][q+(l-j)]:
              cnt += 1
          p, q = i-(l-j), j+(k-i)
          if p in range(9) and q in range(9) and p+(k-i) in range(9) and q+(l-j) in range(9) and S[p][q] and S[p+(k-i)][q+(l-j)]:
              cnt += 1

# print(cnt)
print(cnt // 8)

"""
##.....##
##.....##
.........
.##....#.
.##..#...
........#
......#..
.........
#.......#
"""