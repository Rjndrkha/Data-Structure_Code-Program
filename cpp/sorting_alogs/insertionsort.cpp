#include <bits/stdc++.h>
using namespace std;
#define ll long long int 

void insertion_sort(int *a, int d)
{
    for (int i = 1; i < d; i++)
    {
        int picked = a[i];
        int j = i - 1;
        while (a[j] > picked && j >= 0)
        {
            a[j+1]= a[j];
            j--;
        }

        a[j+1] = picked;
    }
}

int main()
{
    int a[] = {12, 34, 45, 234, 123, 543, 12, 31, 43};

    insertion_sort(a, 9);

    for(int i = 0;i<9;i++){
        cout<<a[i]<<" ";
    }

    return 0;
}