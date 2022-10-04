# (d) write a python program to perform the binary search

def binary_search(list, item):
    low = 0
    high = len(list) - 1

    while low <= high:
        mid = (low + high) // 2
        guess = list[mid]
        if guess == item:
            return mid
        if guess > item:
            high = mid - 1
        else:
            low = mid + 1
    return None


list = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
item = int(input("Enter the item to be searched: "))
index = binary_search(list, item)
if index == -1:
    print("Item not found")
else:
    print("Item found at index: ", index)

print(list)