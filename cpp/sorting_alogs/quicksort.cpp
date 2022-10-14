#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void quick_sort(int *a, int low, int high)
{
    if (low < high)
    {
        int pivot = a[low];
        int lb = low;
        int ub = high;

        while (lb <= ub)
        {
            while ((a[lb] <= pivot) && (lb <= high))
                lb++;

            while ((a[ub] > pivot) && (ub >= low))
                ub--;

            if (lb < ub)
            {
                swap(a[lb], a[ub]);
            }
        }
        swap(a[low], a[ub]);
        quick_sort(a, low, ub - 1);
        quick_sort(a, ub + 1, high);
    }
}

int main()
{
    int a[] = {12, 34, 45, 234, 123, 543, 12, 31, 43};

    quick_sort(a, 0, 8);

    for (int i = 0; i < 9; i++)
    {
        cout << a[i] << " ";
    }

    return 0;
}