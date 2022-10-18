# Selection sort in Python time complexity O(n*n) 
def selectionSort(array, size):
    
    for index in range(size):
        min_index = index
 
        for j in range(index + 1, size):
            # select the minimum element in every iteration
            if array[j] < array[min_index]:
                min_index = j
         # swapping the elements to sort the array
        (array[index], array[min_index]) = (array[min_index], array[index])
 
arr = [2,12,-2,-3,-100,0,23,4,1]
size = len(arr)
selectionSort(arr, size)
print('The array after sorting in Ascending Order is:')
print(arr)
