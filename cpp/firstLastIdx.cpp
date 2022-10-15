#include <bits/stdc++.h>
using namespace std;

// finding the first index, here we wont stop if we get the number, 
// but we will continue to find another element greater thant the 
// number we get (index wise)
int firstIdx(int arr[], int digit, int num)
{

    int start = 0;
    int end = num - 1;
    int ans = -1;

    while (start <= end)
    {
        int mid = (start + end) / 2;

        if (arr[mid] == digit)
        {
            ans = mid;
            end = mid - 1; 
        }

        else if (arr[mid] > digit)
        {
            end = mid - 1;
        }

        else 
        {
            start = mid + 1;
        }
    }

    return ans;
}

// finding the last index, here we wont stop if we get the number, 
// but we will continue to find another element lesser than the 
// number we get (index wise)
int lastIdx(int arr[], int digit, int num)
{

    int start = 0;
    int end = num - 1;
    int ans = -1;

    while (start <= end)
    {
        int mid = (start + end) / 2;

        if (arr[mid] == digit)
        {
            ans = mid;
            start = mid + 1; 
        }

        else if (arr[mid] > digit)
        {
            end = mid - 1;
        }

        else 
        {
            start = mid + 1;
        }
    }

    return ans;
}

int main()
{
    // freopen("input.txt","r",stdin);
    
    int num;

    cin>>num;

    int arr[num];

    for (int idx = 0; idx < num; idx++)
    {
        cin>>arr[idx];
    }

    int digit;

    cin>>digit;

    cout<<firstIdx(arr, digit, num);

    cout<<endl;

    cout<<lastIdx(arr, digit, num);

    return 0;
}