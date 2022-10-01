#include<bits/stdc++.h>
using namespace std;
 
class Graph
{
    int V;  
 
    map<int,bool> vis;
	//vis.resize(V,false);
    vector<list<int>> adj;  
public:
    Graph(int V);  
	
   
    void addedge(int v, int w);
 
    
    void DFS(int s); 
};
 
Graph::Graph(int V)
{
    this->V = V;
    adj.resize(V);
}
 
void Graph::addedge(int v, int w)
{
    adj[v].push_back(w); 
}
 
void Graph::DFS(int s)
{
    vis[s]=true;
	cout<<s<<" ";

	for(auto i:adj[s])
	{
		if(!vis[i])
		{
			DFS(i);
		}
	}
	
}
 

int main()
{
    
    Graph g(4);
    g.addedge(0, 1);
    g.addedge(0, 2);
    g.addedge(1, 2);
    g.addedge(2, 0);
    g.addedge(2, 3);
    g.addedge(3, 3);
 
    cout << "Deapth First Traversal :"
         << "(starting from vertex 2) \n";
    g.DFS(2);
	cout<<endl;
 
    return 0;
}