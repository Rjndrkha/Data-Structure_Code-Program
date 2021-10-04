#include <stdio.h>
#define Max 100

int Insertion_sort(int A[],int n)
{
  int j,i,key;
  for(j=1;j<n;j++)
  {
    key=A[j];
    i=j-1;
    while(i>=0 && key<A[i])
    {
      A[i+1]=A[i];
      i--;
    }
    A[i+1]=key;
    printf("Iteration %d is :",j);
  	for(i=0;i<n;i++)
  	{
    	printf("%d ",A[i]);
 	}
	printf("\n");
   }
}
int main(void) {
  int n,A[Max],i;
  printf("Enter the number of Elements in array :");
  scanf("%d",&n);
  printf("Enter the Elements of array: ");
  for(i=0; i<n ;i++)
    scanf("%d",&A[i]);
    printf("Array is : ");
	for(i=0;i<n;i++)
	printf("%d ",A[i]);	
	printf("\n");
  	Insertion_sort(A,n); 
	printf("\nSorted list is : ");
	for(i=0;i<n;i++)
	printf("%d ",A[i]);	
}
