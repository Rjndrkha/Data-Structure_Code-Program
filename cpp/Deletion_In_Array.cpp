#include<iostream>
using namespace std;
int main()
{
	int n;
	cout<<"Enter the no. of elements:\n";
	cin>>n;
	int arr[n];
	cout<<"Enter the elements in Array:\n";
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	cout<<"Elements in Array before Deletion:\n";
	for(int i=0;i<n;i++)
	{
		cout<<arr[i];
		cout<<"\n";
	}
	cout<<"enter the position to be deleted:\n";
	int pos;
	cin>>pos;
	for(int i=(pos-1);i<n-1;i++){
		arr[i]=arr[i+1];
	}
	cout<<"Elements in array after deletion:\n";
	for(int i=0;i<n-1;i++)
	{
		cout<<arr[i];
		cout<<"\n";
	}
	return 0;
}
