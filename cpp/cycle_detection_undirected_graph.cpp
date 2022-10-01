
/*
    Authors Name :  Mayuri Kolhe
    Date Modified:  01 October, 2022
*/

// Problem: https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

// Solution:
class Solution {
  public:
    bool dfs(int i,int parent,vector<int> &vis, vector<int> adj[]){
        vis[i]=1;
        for(auto j:adj[i]){
            if(vis[j]) {
                if(parent!=j) return true;
                else continue;
            }
            if(dfs(j,i,vis,adj)) return true;
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        vector<int> vis(V,0);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(dfs(i,-1,vis,adj)) return true;
            }
        }
        return false;
    }
};
