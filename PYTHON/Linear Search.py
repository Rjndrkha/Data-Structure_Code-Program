lst=[]
n=int(input("enter the length of the list you want to enter in"))
for i in range(n):
    lst.append(int(input(f"enter element at {i} position")))

#input for the key
num=int(input("enter the number that you want to find in.\n"))

a=[]
flag=False
for i in range(len(lst)):
    if(num==lst[i]):
        a.append(i)
if (len(a)==0):
    print(num,'is not present in the list')
else:
    print(num,'is found at index',*a)