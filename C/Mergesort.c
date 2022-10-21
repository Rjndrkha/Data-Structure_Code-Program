#include <stdio.h>

#define size 50

int a[size];
int b[size];

void merging(int low, int mid, int high) {
  int h,i,j;//l2=j,i=i;l1=h
   for(h = low, j = mid + 1, i = low; h <= mid && j <= high; i++) {
      if(a[h] <= a[j])
         b[i] = a[h++];
      else
         b[i] = a[j++];
   }
   
   while(h <= mid)    
      b[i++] = a[h++];

   while(j <= high)   
      b[i++] = a[j++];

   for(i = low; i <= high; i++)
      a[i] = b[i];
}

void Mergesort(int low, int high) {
   int mid;
   
   if(low < high) {
      mid = (low + high) / 2;
      Mergesort(low, mid);
      Mergesort(mid+1, high);
      merging(low, mid, high);
   } else { 
      return;
   }   
}

int main() { 
   int i,n;
   printf("Enter the size of array : ");
   for(i=0;i<n;i++)
   scanf("%d",&n);
   printf("List before sorting\n");
   
   for(i = 0; i <n; i++)
      printf("%d ", a[i]);

   Mergesort(0,n-1);

   printf("\nList after sorting\n");
   
   for(i = 0; i <n; i++)
      printf("%d ", a[i]);
}
