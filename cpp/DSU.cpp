/*
Author's Name : mayuri kolhe
Date : 1st October 2022
*/

#include<bits/stdc++.h>
using namespace std;

class DSU{
	vector<int> par, rank;
public:
	DSU(int n){
		par.clear();
		rank.clear();
		rank.resize(n, 1);
		par.resize(n, 1);
		// initialises par (parent) vector with 0, 1, 2, 3, 4 ...
		iota(par.begin(), par.end(), 0);
	}

	// find parent of node in a component
	int findPar(int node){
		if(node == par[node]) 
			return node;
		// Compression part/step
		return par[node] = findPar(par[node]);
	}

	// merge two components
	void merge(int u, int v){
		int u_parent = findPar(u);
		int v_parent = findPar(v);

		if(rank[u_parent] < rank[v_parent])
			par[u_parent] = v_parent;
		else if(rank[u_parent] > rank[v_parent])
			par[v_parent] = u_parent;
		else{
			// rank is updated when both nodes have same rank/size
			par[v_parent] = u_parent;
			rank[u_parent]++;
		}
	}
};
