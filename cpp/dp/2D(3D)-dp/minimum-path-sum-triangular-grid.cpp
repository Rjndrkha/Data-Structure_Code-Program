#include <bits/stdc++.h>

using namespace std;

int minimumPathSumUtil(int i, int j, vector<vector<int> > &triangle,int n, 
vector<vector<int> > &dp) {
  
  if(dp[i][j]!=-1)
  return dp[i][j];
  
  if(i==n-1) return triangle[i][j];
    
  int down = triangle[i][j]+minimumPathSumUtil(i+1,j,triangle,n,dp);
  int diagonal = triangle[i][j]+minimumPathSumUtil(i+1,j+1,triangle,n,dp);
  
  return dp[i][j] = min(down, diagonal);
  
}

int minimumPathSum(vector<vector<int> > &triangle, int n){
    vector<vector<int> > dp(n,vector<int>(n,-1));
    return minimumPathSumUtil(0,0,triangle,n,dp);
    
}

int main() {

  vector<vector<int> > triangle{{1},
                                {2,3},
                                {3,6,7},
                                {8,9,6,10}};
                            
  int n = triangle.size();
  
  cout<<minimumPathSum(triangle,n);
}