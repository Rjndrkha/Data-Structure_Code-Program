def bubblesort(list2):
    for j in range(len(list2)-1,0,-1):
        for i in range(j):
            if list2[i] > list2[i+1]:
                list2[i], list2[i+1] = list2[i+1], list2[i]
