#include<stdio.h>
int main()
{
    int a,b;
    print("Enter the 2 numbers to be swapped \n");
    scanf("%d%d",&a,&b);
    a = a + b;  
    b = a - b;  
    a = a - b;
    printf("The numbers a and b after swapping are a: %d and b: %d",a,b);
    return 0;
}