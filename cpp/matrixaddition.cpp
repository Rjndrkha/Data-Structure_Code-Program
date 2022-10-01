/*
    Authors Name : Mayuri Kolhe
    Date Modified: 1 October, 2022
*/


/* Program to add two matrices*/

#include <iostream>
using namespace std;
 
int main()
{
        int r, c, a[100][100], b[100][100], sum[100][100], i, j;
 
        cout<<"Enter number of rows (between 1 and 100): ";
        cin>>r;
        cout<<"Enter number of columns (between 1 and 100): ";
        cin>>c;
 
        cout<<"\nEnter elements of First matrix:\n";
 
        for(i=0; i<r; ++i)
        for(j=0; j<c; ++j)
        {
            cout<<"Enter element a"<<i+1<<j+1<<": ";
            cin>>a[i][j];
        }
 
        cout<<"Enter elements of Second matrix:\n";
        for(i=0; i<r; ++i)
        for(j=0; j<c; ++j)
        {
            cout<<"Enter element a"<<i+1<<j+1<<": ";
            cin>>b[i][j];
        }
 
        // Adding Two matrices
 
        for(i=0;i<r;++i)
        for(j=0;j<c;++j)
        {
            sum[i][j]=a[i][j]+b[i][j];
        }
 
        // Displaying the result
        cout<<"\nSum of two matrix is: \n\n";
 
        for(i=0;i<r;++i)
        for(j=0;j<c;++j)
        {
 
            cout<<"\t"<<sum[i][j];
 
            if(j==c-1)
            {
                cout<<"\n\n";
            }
        }
 
    return 0;
}