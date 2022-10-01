#include <stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++)
    scanf("%d",&a[i]);
    for(int i=0;i<n;i+=2)
    {
        if(i>0 && a[i-1]>a[i])
        {
          int t=a[i];
          a[i]=a[i-1];
          a[i-1]=t;
        }
        if(i<=n-2 && a[i+1]>a[i])
        {
          int t=a[i];
          a[i]=a[i+1];
          a[i+1]=t;
        }
    }
    for(int i=0;i<n;i++)
    printf("%d ",a[i]);
    return 0;
}
