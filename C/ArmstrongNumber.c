#include<stdio.h>  
 int main()    
{    
int n,r,res=0,temp;    
printf("enter the number=");    
scanf("%d",&n);    
temp=n;    
while(temp != 0)    
{    
 // remainder contains the last digit
r=temp%10;    
res += r*r*r;   
 // removing last digit from the orignal number
n/=10;    
}    
if(temp==res)    
printf("armstrong  number ", n);    
else    
printf("not armstrong number", n);    
return 0;  
}   
