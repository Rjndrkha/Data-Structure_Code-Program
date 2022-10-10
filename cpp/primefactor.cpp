#include<iostream>
#include<cmath>
using namespace std;
void printPrimeFactors(int n)
{
	if(n<=1)
	return;
	for(int i=2;i*i<=n;i++)
	{
		while(n%i==0)
		{
			cout<<i<<endl;
			n=n/i;
		}
	}
	if(n>1)
	cout<<n;
} 
int main()
{ int a;
cout<<"enter number"<<a<<endl;
cin>>a;
printPrimeFactors(a);
}