#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"enter the size:"<<endl;
    cin>>n;
    int a[n];
    cout<<"enter the elements:"<<endl;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    // lets create a left array:-
    int b[n],c[n];
    int max=a[0];
    for(int i=0;i<n;i++){
    
        if(a[i]>max){
            max=a[i];
            b[i]=max;
        }
        else{
            b[i]=max;
        }
    }
   //lets create right array
    int large=a[n-1];
    for(int i=n-1;i>=0;i--){
if(a[i]>large){
    large=a[i];
    c[i]=large;
}
else{
    c[i]=large;
}
    }
    int sum=0;
    for(int i=0;i<n;i++)
    {
        if(b[i]>c[i]){
            sum=sum+(c[i]-a[i]);
        }
        else{
            sum=sum+(b[i]-a[i]);
        }
    }
    cout<<sum<<endl;
return 0;
}
