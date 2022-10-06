#include <bits/stdc++.h>
using namespace std;

vector<int > adj[1005];
vector<int > vis(1005);

bool cycle(int u,int par){
    vis[u]=1;
    for(auto i : adj[u]){
        if(vis[i]==0){
            if(cycle(i,u)==true){
                return true;
            }
        }else{
            if(i!=u){
                return true;
            }
        }
    }
    return false;
}
int main() {
    
    int n,e,x,y;
    cin>>n>>e;
    for(int i=0;i<e;i++){
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);

    }
    if(!cycle(1,0)){
        cout<<"no cycle found"<<endl;
    }
    else{
        cout<<"cycle detected"<<endl;
    }
}
