#include <bits/stdc++.h>

using namespace std;

int knapsackUtil(vector<int>& wt, vector<int>& val, int ind, int W, vector<vector<int>>& dp){

    if(ind == 0){
        if(wt[0] <=W) return val[0];
        else return 0;
    }
    
    if(dp[ind][W]!=-1)
        return dp[ind][W];
        
    int notTaken = 0 + knapsackUtil(wt,val,ind-1,W,dp);
    
    int taken = INT_MIN;
    if(wt[ind] <= W)
        taken = val[ind] + knapsackUtil(wt,val,ind-1,W-wt[ind],dp);
        
    return dp[ind][W] = max(notTaken,taken);
}


int knapsack(vector<int>& wt, vector<int>& val, int n, int W){
    
    vector<vector<int>> dp(n,vector<int>(W+1,-1));
    return knapsackUtil(wt, val, n-1, W, dp);
}

int main() {

  vector<int> wt = {1,2,4,5};
  vector<int> val = {5,4,8,6};
  int W=5;
  
  int n = wt.size();
                                 
  cout<<"The Maximum value of items, thief can steal is " <<knapsack(wt,val,n,W);
}
