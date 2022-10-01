#include<iostream>
using namespace std;
 void soe(int n){
  int ar[100]={0};

  for(int i=2;i<=n;i++){
     if(ar[i]==0){
         for(int j=i*i;j<=n;j+=i){
             ar[j]=1;
         }
     }
  }   
  for(int i=2;i<=n;i++){
      if(ar[i]==0){
          cout<<i<<" ";
      }
  }cout<<endl;
 }
int main(){
    int n;
    cin>>n;
   soe(n);
} 