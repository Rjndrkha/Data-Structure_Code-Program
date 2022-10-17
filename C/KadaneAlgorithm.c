#include <stdio.h>

void LARGESTSUM(int a[], int n)
{
  int curSum = 0;
  int maxSum = a[0];
  int start = 0, end = 0, s = 0;
  for (int i = 0; i < n; i++)
  {
    curSum = curSum + a[i];
    if (curSum > maxSum)
    {
      maxSum = curSum;
      start = s;
      end = i;
    }
    if (curSum < 0)
    {
      curSum = 0;
      s = i + 1;
    }
  }
  printf("The maximum Sum is: %d\n", maxSum);
  printf("Start: %d\n", start+1);
  printf("End: %d\n", end+1);
}

int main()
{
  int a[10], n;
  printf("Enter the no. of array elements (<10): ");
  scanf("%d", &n);
  printf("Enter the array elements: ");
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &a[i]);
  }
  LARGESTSUM(a, n);
}
