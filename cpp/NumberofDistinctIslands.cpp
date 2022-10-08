// Number of Distinct Islands
// GFG
// Question link : https://practice.geeksforgeeks.org/problems/number-of-distinct-islands/1


class Solution {
  public:
  void helper(vector<vector<int>> &grid,int i,int j,string &st){
if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j]==0)return ;
      grid[i][j]=0;
      st=st+"d";
      helper(grid,i+1,j,st);
      st=st+"u";
      helper(grid,i-1,j,st);
      st=st+"r";
      helper(grid,i,j+1,st);
      st=st+"l";
      helper(grid,i,j-1,st);
  }
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int count=0;
 int n=grid.size();
 int m=grid[0].size();
 unordered_map<string,int> mp;
 for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
          if(grid[i][j]==1){
             string st="";
             helper(grid,i,j,st);
             if(mp.find(st)==mp.end()){
                  count++;    
              }
              mp[st]++;
           }
      }
  }
  return count;
    }
};
