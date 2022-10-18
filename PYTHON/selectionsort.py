# Utility function to swap values at two indices in the list
def swap(A, i, j):
 
    temp = A[i]
    A[i] = A[j]
    A[j] = temp
 
 
# Recursive function to perform selection sort on sublist `A[i…n-1]`
def selectionSort(A, i, n):
 
    # find the minimum element in the unsorted sublist `A[i…n-1]`
    # and swap it with `A[i]`
    min = i
    for j in range(i + 1, n):
 
        # if the `A[j]` element is less, then it is the new minimum
        if A[j] < A[min]:
            min = j            # update the index of minimum element
 
    # swap the minimum element in sublist `A[i…n-1]` with `A[i]`
    swap(A, min, i)
 
    if i + 1 < n:
        selectionSort(A, i + 1, n)
 
 
if __name__ == '__main__':
 
    A = [3, 5, 8, 4, 1, 9, -2]
 
    selectionSort(A, 0, len(A))
 
    # print the sorted list
    print(A)
 
