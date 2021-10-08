#include<iostream>
using namespace std;
int lucky_index(int n,int k)
{
    if(n==1)
        return 0;
    return (lucky_index(n-1,k)+k)%n;
    
}

int main(int argc,char* argv[])
{
    int  n,k;
    cin>>n>>k;
    cout<<lucky_index(n,k);

       
 
    
}