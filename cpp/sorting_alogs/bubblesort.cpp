#include <bits/stdc++.h>
using namespace std;

void swap_a(int *aj, int *aj1)
{
    int temp = *aj1;
    *aj1 = *aj;
    *aj = temp;
}

void bubble_sort(int *a, int k)
{
    bool ok = false;
    int pass = 0;

    for (int i = 0; i < k-1; i++)
    {
        ok = 0;
        pass = i;                                    
        for (int j = 0; j < k - 1 - pass; j++)
        {

            if (a[j] > a[j + 1])
            {   
                cout<<j<<endl;
                swap_a(&a[j], &a[j + 1]);
                ok =1;
            }

            
        }
        if(ok == 0){
            break;
        }
    }
}

int main()
{
    int a[6] = {7, 4, 2, 1, 5, 8};

    bubble_sort(a, 6);
    for (int i = 0; i < 6; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}