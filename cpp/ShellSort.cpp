#include <iostream>  
using namespace std;  
/* function to implement shellSort */  
int shell(int a[], int n)  
{  
    /* Rearrange the array elements at n/2, n/4, ..., 1 intervals */  
    for (int interval = n/2; interval > 0; interval /= 2)  
    {  
        for (int i = interval; i < n; i += 1)  
        {  
            /* store a[i] to the variable temp and make the ith position empty */  
            int temp = a[i];  
            int j;        
            for (j = i; j >= interval && a[j - interval] > temp; j -= interval)  
                a[j] = a[j - interval];  
              
            // put temp (the original a[i]) in its correct position  
            a[j] = temp;  
        }  
    }  
    return 0;  
}  
void printArr(int a[], int n) /* function to print the array elements */  
{  
    int i;  
    for (i = 0; i < n; i++)  
        cout<<a[i]<<" ";  
}      
int main()  
{  
    int a[] = { 32, 30, 39, 7, 11, 16, 24, 41 };  
    int n = sizeof(a) / sizeof(a[0]);  
    cout<<"Before sorting array elements are - \n";  
    printArr(a, n);  
    shell(a, n);  
    cout<<"\nAfter applying shell sort, the array elements are - \n";    
    printArr(a, n);  
    return 0;  
}  
