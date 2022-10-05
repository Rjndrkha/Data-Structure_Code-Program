#include<bits/stdc++.h>
using namespace std;


// largest row sum
void rowSum(int arr[3][3])
{   int max = -1, ans = 0;
    for (int i = 0; i < 3; i++)
    {
        int sum = 0;
        for (int j = 0; j < 3; j++) 
        {
            sum += arr[i][j];
        }
        if (sum > max) 
        {
            max = sum;
            ans = i;
        }
    }
    cout << "Largest sum = " << max << " Row Index = " << ans;
}
int main()
{
    int arr[3][3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++) cin >> arr[i][j]; 

    }
    rowSum(arr);
}