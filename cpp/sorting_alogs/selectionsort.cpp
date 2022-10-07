#include <bits/stdc++.h>
using namespace std;

void swap_a(int *ai, int *aj)
{
    int temp = *aj;
    *aj = *ai;
    *ai = temp;
}

void selection_sort(int *a, int n)
{
    int i, j;

    for (i = 0; i < n - 1; i++)
    {
        int min = a[i];
        int min_indx = i;

        for (j = i + 1; j < n; j++)
        {
            if (a[j] < a[min_indx])
            {
                min = a[j];
                min_indx = j;
            }
        }

        swap_a(&a[i], &a[min_indx]);
    }
}

int main()
{
    int a[6] = {7, 43, 12, 1, 6, 5};

    selection_sort(a, 6);

    for (int i = 0; i < 6; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}