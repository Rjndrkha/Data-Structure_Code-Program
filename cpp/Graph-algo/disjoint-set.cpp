#include <bits/stdc++.h>
using namespace std;

int parent[1000], rank[1000];
void makeSet(int N){
	for(int i=0; i<N; i++){
		parent[i] = i;
		rank[i] = 0;
	}
}
int findPar(int node){
	if(node == parent[node]){
		return  node;
	}
	return parent[node] = findPar(parent[node]);
	
}

void unionOp(int u, int v){
	u = findPar(u);
	v = findPar(v);
  if(rank[u] > rank[v]){
		parent[v] = u;
	}
	else if(rank[v] > rank[u]){
		parent[u] = v;
	}
	else{
		parent[v] = u;
		rank[u]++;
	}
}


