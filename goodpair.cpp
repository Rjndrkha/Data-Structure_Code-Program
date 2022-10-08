#include<bits/stdc++.h>
using namespace std;

// int count =0
// set<int>s;
// for(int x:A){
// s.insert(x)}
// fir(int i=0;i<s.size()-1;i++){
// Count+=s.size()-i-1;}
// Return count; 
void Solution(vector<int> &A) {
   multimap<int,int> m;
int c=0;
for(int i:A)
    for(int j:A)
        if(i<j)
            m.emplace(i,j);
for(auto i:m)
    c++;
cout<< c;

}

int main(){
    
    vector<int> a={2,4,1,8,7,0};
 
    Solution(a);

    return 0;
}