#include<bits/stdc++.h>
using namespace std;

// single source shortest path - Dijkstra Algo

class Graph{

    int v;
    vector<vector<pair<int,int>>> adj;
    vector<int> distance;
public:
    Graph(int n){
        this->v = n;
        adj.resize(v);
        distance.resize(v, INT_MAX);
    }

    void AddEdge(int a, int b,int wt, bool undir){
        adj[a].push_back({b,wt});
        if (undir)
        {
            adj[b].push_back({a,wt});
        }
    }

    void Dijkstra(int source){
        
        priority_queue<pair<int,int> ,vector<pair<int,int>>, greater<pair<int,int>>> q;  // distance ,node ; min heap

        q.push({0,source});
        distance[source] = 0;

        while (!q.empty())
        {   
            pair<int,int> temp = q.top();

            // loop on adj[source] ->nbr;
            for(auto nbr: adj[temp.second]){
                if (distance[nbr.first] > distance[temp.second] + nbr.second)
                {
                    q.push({nbr.second, nbr.first});
                    distance[nbr.first] = distance[temp.second] + nbr.second;
                }
            }
            q.pop();
        }
        
        for(int i = 0; i< v; i++){
            cout<<"Distance of "<<i<<" is "<<distance[i]<<endl;
        }
    }
};

int main(){
    
    Graph g(5);
    g.AddEdge(0, 1, 2, 1); // a, b, wt ,undir
    g.AddEdge(0, 3, 1, 1);
    g.AddEdge(1, 4, 5, 1);
    g.AddEdge(1, 2, 4, 1);
    g.AddEdge(2, 3, 3, 1);
    g.AddEdge(2, 4, 1, 1);

    g.Dijkstra(0);
    return 0;
}
