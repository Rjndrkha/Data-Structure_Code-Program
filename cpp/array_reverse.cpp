#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"enter the number of elements in an array "; //input regarding total number of elemets in array
    cin>>n;
    int a[n];
    cout<<"enter the elements of an array "<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];                                    //input the elements of array
    }
    int b[n];                                        //creating a new array having same size
    for(int i=n-1,j=0;i>=0;i--,j++)                   
    b[j]=a[i];                                       //copying the elements in reverse order in newly created array
    for(int i=0;i<n;i++)
    a[i]=b[i];                                       //copying the elements in original array
    cout<<"the reverse array is ";
    for(int i=0;i<n;i++)
    cout<<a[i]<<" ";                                 //display of reverse array
}
