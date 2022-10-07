#include<bits/stdc++.h>
using namespace std;

void merge(int *a,int s,int e)
{
    int mid = (s+e)/2;
    int l1=  mid-s+1;
    int l2 = e-mid;
    int *first= new int[l1];
    int *second= new int[l2];
    int k = s;
    for(int i=0;i<l1;i++)
    {
        first[i] = a[k++];
    }
     k = mid+1;
    for(int i=0;i<l2;i++)
    {
        second[i] = a[k++];
    }
    int i1=0,i2=0;
    k = s;
    while (i1<l1 && i2<l2)
    {
        if(first[i1]<second[i2])
        {
            a[k++] = first[i1++];
        }
        else
        {
             a[k++] = second[i2++];
        }
    }
    while (i1<l1)
    {
        a[k++] = first[i1++];
    }
    while (i2<l2)
    {
        a[k++] = second[i2++];
    }
    
    delete first;
    delete second;
    
}
void mergeSort(int *a,int s, int e)
{
    if(s>=e){
        return;
    }
   int  mid = (s+e)/2;
    mergeSort(a,s,mid);
    mergeSort(a,mid+1,e);
    merge(a,s,e);
}
int main()
{
    int arr[] = {2,1,1,6,4};
    int n=5;
    mergeSort(arr,0,n-1);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}