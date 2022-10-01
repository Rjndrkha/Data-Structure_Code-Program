/*
    Authors Name : Mayuri Kolhe
    Date Modified: 1 October, 2022
*/


/* Program to find Transpose of a matrix */

#include <iostream>
using namespace std;
 
int main()
{
    static int array[10][10];
    int i, j, m, n;
 
    cout<<"Enter the order of the matrix \n";
    // Inputing elements in matrix from user
    cin>>m>>n;
    cout<<"Enter the coefiicients of the matrix\n";
    for (i = 0; i < m; ++i)
    {
        for (j = 0; j < n; ++j)
        {
            cin>>array[i][j];
        }
    }
    //Printing the original matrix
    cout<<"The given matrix is \n";
    for (i = 0; i < m; ++i)
    {
        for (j = 0; j < n; ++j)
        {
            cout<<" "<<array[i][j];
        }
        cout<<"\n";
    }
    //Printing the transpose of matrix
    cout<<"Transpose of matrix is \n";
    for (j = 0; j < n; ++j)
    {
        for (i = 0; i < m; ++i)
        {
           cout<<" "<<array[i][j];
        }
        cout<<"\n";
    }
    return 0;
}