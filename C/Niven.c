#include<stdio.h>
#include<conio.h>
 
int main()
{
    int number,original_number,sum=0;
    int digit;
 
    printf("Enter a number \n");
    scanf("%d",&original_number);
 
    number=original_number;
 
    while(number!=0)
    {
        digit=number%10;
        sum+=digit;
        number=number/10;
    }
 
    if(original_number%sum==0)
        printf("Niven NUMBER \n");
    else
        printf("NOT A Niven NUMBER");
 
    return 0;
}
