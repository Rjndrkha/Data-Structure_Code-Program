#include <bits/stdc++.h>

using namespace std;

bool subsetSumUtil(int ind, int target, vector<int>& arr, vector<vector<int>> &dp){
    if(target==0)
        return true;
    
    if(ind == 0)
        return arr[0] == target;
    
    if(dp[ind][target]!=-1)
        return dp[ind][target];
        
    bool notTaken = subsetSumUtil(ind-1,target,arr,dp);
    
    bool taken = false;
    if(arr[ind]<=target)
        taken = subsetSumUtil(ind-1,target-arr[ind],arr,dp);
        
    return dp[ind][target]= notTaken||taken;
}

bool canPartition(int n, vector<int> &arr){
    
    int totSum=0;
    
    for(int i=0; i<n;i++){
        totSum+= arr[i];
    }
    
    if (totSum%2==1) return false;
    
    else{
        int k = totSum/2;
        vector<vector<int>> dp(n,vector<int>(k+1,-1));
        return subsetSumUtil(n-1,k,arr,dp);
    } 
}

int main() {

  vector<int> arr = {2,3,3,3,4,5};
  int n = arr.size();
                                 
  if(canPartition(n,arr))
    cout<<"The Array can be partitioned into two equal subsets";
  else 
    cout<<"The Array cannot be partitioned into two equal subsets";
}
