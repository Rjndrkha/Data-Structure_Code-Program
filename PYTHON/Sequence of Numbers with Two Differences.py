a=int(input("enter first number))
b=int(input("enter second number))
c=int(input("enter third number ))
n=int(input("nth number))
d1=b-a
d2=c-b
m=a
for i in range(1,n):
    if i%2==0:
        m+=d2
    else:
        m+=d1
        
print(m)
