// Codechef
// DSA Learning Series
// Contest 1
// Problem Code: LAPIN


#include<iostream>
#include<map>
// #include<cstring>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        int lenstr;
        cin>>str;
        lenstr = str.size();
        map<char, int> first, last;
        for(int i=0, j=lenstr-1; i<lenstr/2;i++,j--){
            first[str[i]]++;
            last[str[j]]++;
        }
        if(first == last){
            cout<<"YES"<<endl;
        }
        else    
            cout<<"NO"<<endl;
    }
    return 0;
}