/* C Program to replace all Even elements by 0 and Odd by 1  */

#include <stdio.h>

void readArray(int arr[], int size)
{
    int i =0;

    printf("Enter elements of array :: \n");

    for(i=0; i < size; i++)
    {
        printf("\nEnter arr[%d] :: ",i);
        scanf("%d",&arr[i]);
    }
}

void printArray(int arr[], int size)
{
    int i =0;

    printf("\nElements are : ");

    for(i=0; i < size; i++)
    {
        printf("\narr[%d] : %d",i,arr[i]);
    }
    printf("\n");
}

void replaceEvenOdd(int arr[], int size)
{
    int i=0;

    for(i=0; i < size; i++)
    {
        if( arr[i] % 2 == 0 )
            arr[i] = 0 ;
        else
            arr[i] = 1 ;
    }
}

int main()
{
    int arr[10];

    readArray(arr,10);

    printf("\nBefore replacement : ");
    printArray(arr,10);

    replaceEvenOdd(arr,10);

    printf("\nAfter replacement : ");
    printArray(arr,10);

    return 0;
}
