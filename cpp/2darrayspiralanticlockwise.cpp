#include<iostream>
using namespace std;

int main() {
    int arr[10][10];
    int m,n; cin>>m>>n;
    int i,j,k;
    cout<<"enter the elements of the array"<<endl;
    for (i=0; i<m; i++)
    {
        for (j=0; j<n;j++)
        {
            cin>>arr[i][j];
        }
    }

    int cs=0, ce=n-1, rs=0, re=m-1;
    while (rs<=re && cs<=ce)
    {
        for (k=rs; k<=re; k++)
        cout<<arr[k][cs]<<", ";
        cs++;
        for (k=cs; k<=ce; k++)
        cout<<arr[re][k]<<", ";
        re--;
        if (cs>ce || rs>re) break;
        for (k=re; k>=rs; k--)
        cout<<arr[k][ce]<<", ";
        ce--;
        for (k=ce; k>=cs; k--)
        cout<<arr[rs][k]<<", ";
        rs++;
    }
    cout<<"END OF THE PATTERN";
	return 0;
}