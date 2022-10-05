#include <bits/stdc++.h>
using namespace std;

int editDistanceUtil(string& S1, string& S2, int i, int j, vector<vector<int>>& dp){
    
    if(i<0)
        return j+1;
    if(j<0)
        return i+1;
        
    if(dp[i][j]!=-1) return dp[i][j];
        
    if(S1[i]==S2[j])
        return dp[i][j] =  0+editDistanceUtil(S1,S2,i-1,j-1,dp);
        
    // Minimum of three choices
    else return dp[i][j] = 1+min(editDistanceUtil(S1,S2,i-1,j-1,dp),
    min(editDistanceUtil(S1,S2,i-1,j,dp),editDistanceUtil(S1,S2,i,j-1,dp)));
    
}

int editDistance(string& S1, string& S2){
    
    int n = S1.size();
    int m = S2.size();
    
    vector<vector<int>> dp(n,vector<int>(m,-1));
    return editDistanceUtil(S1,S2,n-1,m-1,dp);
    
}

int main() {

  string s1 = "horse";
  string s2 = "ros";

  cout << "The minimum number of operations required is: "<<editDistance(s1,s2);
}