#include<bits/stdc++.h>
using namespace std;
int main(){
    int  node,edge;
    cin>>node>>edge;
    vector<pair<int,int>>adj[node];
    for(int i=0;i<edge;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back(make_pair(v,w));                        //TC:O(edge*log(node))
        adj[v].push_back(make_pair(v,w));                        //SC:adj list + key,parent,mst array + priority queue
    }

    int key[node];
    int parent[node];
    bool mst[node];

    for(int i=0;i<node;i++){
        key[i]=INT_MAX;
        parent[i]=-1;
        mst[i]=false;
    }

    priority_queue< pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>> >pq;      //minimum heap

    key[0]=0;
    parent[0]=-1;
    pq.push({0,0});                 //(key,index)

    for(int i=0;i<node-1;i++){                    //while(!pq.empty)
        int hold=pq.top().second;    
        pq.pop();

        mst[hold]=true;

        for(auto it:adj[hold]){
            int v=it.first;
            int weight=it.second;
            if(mst[v]==false && key[v]>weight){
                key[v]=weight;
                parent[v]=hold;
                pq.push({key[v],v});      //instead of key[v],you can push weight also,eventually both are same
            }
        }                                    
    }  

    for(int i=0;i<node;i++){
        cout<<parent[i]<<"--"<<i<<"\n";
    }
    return 0;
}
