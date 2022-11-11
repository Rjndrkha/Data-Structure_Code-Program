from selection_sort import selectionsort
from bubble_sort import bubblesort
from merge_sort import mergesort
from insertion_sort import insertionsort


while True:
    print("# Menu")
    print("1. Selection Sort")
    print("2. Bubble Sort")
    print("3. Merge Sort")
    print("4. Insertion Sort")
    print("5. Credit Title")
    print("0. keluar program")

    menu = input("pilih menu : ")

    if menu == "0":
        break
    elif menu == "1":
        selectionsort
        num = int(input("masukan berapa banyak angka: "))
        list3 = [int(input()) for x in range(num) ]
        print("sebelum di terurut: ", list3)
        selectionsort(list3)
        print("sesudah di urut: ",list3)
    elif menu == "2":
        bubblesort
        num = int(input("masukan berapa banyak angka: "))
        list2 = [int(input()) for x in range(num)]
        print("sebelum berurut", list2)
        mergesort(list2)
        print("yang sudah berurut: ", list2)
    elif menu == "3":
        mergesort
        num = int(input("masukan berapa banyak angka: "))
        list1 = [int(input()) for x in range(num)]
        print("sebelum berurut", list1)
        mergesort(list1)
        print("yang sudah berurut: ", list1)
    elif menu == "4":
        insertionsort
        num = int(input("masukan berapa banyak angka: "))
        my_list = [int(input()) for x in range(num)]
        print("sebelum berurut", my_list)
        insertionsort(my_list)
        print("yang sudah berurut: ", my_list)
    elif menu == "5":
        print("Rikoairlan")
    
print("program selesai berjalan, sampai jumpa")
    
