#1: Simple Number Triangle Pattern
rows = 6

for num in range(rows):
    for i in range(num):
        print(num, end="") # print number
    print("")
print()
#2: Inverted Pyramid of Numbers
rows = 5

b = 0

for i in range(rows, 0, -1):
    b += 1
    for j in range(1, i + 1):
        print(b, end=' ')
    print('\r')
print()


#3: Half Pyramid Pattern of Numbers
rows = 5

for row in range(1, rows+1):
    for column in range(1, row + 1):
        print(column, end=' ')
    print("")
print()


#4: Inverted Pyramid of Descending Numbers
rows = 5
for i in range(rows, 0, -1):
    num = i
    for j in range(0, i):
        print(num, end=' ')
    print("\r")
print()
