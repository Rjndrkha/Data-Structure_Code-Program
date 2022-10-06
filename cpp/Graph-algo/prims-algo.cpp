#include <bits/stdc++.h>
using namespace std;
int main() {
	int N, m;
	cin>>N>>m;
	int a, b, wt;
  vector<pair<int,int>>adj[N];

	for(int i=0; i<m; i++){
		cin>a>>b>>wt;
		adj[a].push_back({b, wt});
		adj[b].push_back({a, wt});
	}
	int key[N];
	int parent[N];
	bool mst[N];
	for(int i=0; i<N; i++){
		key[i] = INT_MAX;
		parent[i] = -1;
		mst[i] = false;
	}
	parent[0] = 0;
	key[0] = 0;
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
	// first value will be weight, second value will be node;
	pq.push({0, 0});
	for(int i=0; i<N-1; i++){
	  int u = pq.top().second;
		pq.pop();
		mst[u] = true;
		for(auto it : adj[u]){
			int node = it.first;
			int wt = it.second;
			if(wt < key[node] && mst[node] == false){
				key[node] = wt;
				pq.push({key[node], node});
				parent[node] = u;
			}
		}
	}
}