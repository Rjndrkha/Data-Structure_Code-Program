#include<iostream>
using namespace std;
int main()
{
    int a[10][10];
    int m=5, n=5;

    for (int i=0;i<m;i++){
        for (int j=0;j<n;j++){
            a[i][j]=i*10+j;
        }
    }
    for (int i=0;i<m;i++){
        for (int j=0;j<n;j++){
            cout<<a[i][j]<<'\t';
        }
        cout<<endl;
    }

    cout<<"Wave print: ";
    for (int j=0; j<n; j++)
    {
        if (j%2==0)
        {
            for (int i=0; i<m; i++)
                cout<<a[i][j]<<" ";
        }
        else
            for (int i=m-1; i>=0; i--)
        {
            cout<<a[i][j]<<" ";
        }
    }




}
