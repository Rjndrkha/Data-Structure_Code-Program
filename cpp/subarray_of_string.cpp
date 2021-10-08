//subarray substring linked lists file stream c_str gcd
// CPP program to count words in a string
// using stringstream.

#include <bits/stdc++.h>
using namespace std;
void subset_strings(string n,string cur ,int index)
{
  
    if(index==n.length())
     {  
         cout<<cur<<" "; 
         return;
     }   
    subset_strings(n,cur,index+1);
    subset_strings(n,cur+n[index],index+1); 
    
    
}
void subarray(int arr[],int N,vector<int> p,int index)
{
        if(index==N)
        {
           if(p.size()==0){
               cout<<"{ } "<<" ";
           }
          else{
              cout<<"{";
            for(auto x:p)
            {
                cout<<x<<",";
            }
            cout<<"}"<<" ";
            }
            return;
        }
        subarray(arr,N,p,index+1);
        p.push_back(arr[index]);
        subarray(arr,N,p,index+1);
}
 int main()
 {
    //  string s="ABC";
    // subset_strings(s," ",0);
   int arr[]={1,2,3};
   vector<int> x;
   subarray(arr,3,x,0);
    

 }
