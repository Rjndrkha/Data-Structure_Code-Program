#include<bits/stdc++.h>
using namespace std;

queue <int> que;

int main(){
	int vertex;
	cout<<"\n-------- Assignment 09 -----------\n";
	cout<<"Enter the vertex : ";
	cin>>vertex;

	int adj[vertex+1][vertex+1];
	int topo[vertex+1] = {0};
	
	for (int i = 0; i <= vertex; i++){
		for (int j = 0; j <= vertex; j++){
			adj[i][j] = 0;
                }
        }
	
	char ch = 'y';

        while(ch =='y'){
        	int x, y;
		cout<<"\nEnter the edges : ";
		cin>>x>>y;
		adj[x][y] = 1;
		topo[y] += 1;
		cout<<"Wanna enter more edges?(y/n) : ";
		cin>>ch; 
        }

	for (int i = 1; i <= vertex; i++){
		if (topo[i] == 0){
			que.push(i);
			topo[i] = -1;
		}
	}

	if(que.empty()){
		cout<<"\nNot an acyclic directed graph!!";
	}

	cout<<"topological Sort: ";
	while(!que.empty()){
		int x = que.front();
		for (int i = 1; i <= vertex; i++){
			if (adj[x][i] == 1){
				topo[i] -= 1;
				if (topo[i] == 0){
					topo[i] = -1;
					que.push(i);
				}
			}
		}
		cout<<" "<<x;
		que.pop();
	}
}