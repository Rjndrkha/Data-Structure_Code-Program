# (c) write a python program to perform the linear search


def linear_search(list, item):
    for i in range(len(list)):
        if list[i] == item:
            return i
    return -1


list = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
item = int(input("Enter the item to be searched: "))
index = linear_search(list, item)
if index == -1:
    print("Item not found")
else:
    print("Item found at index: ", index)

print(list)