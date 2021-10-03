 /*---------------------------------------
 Disjoint Set Data Structure
-----------------------------------------*/

import java.util.*;

public class DSU{
	int[] rank, parent;
	int n;
	//constructor
	public DSU(int n){
		rank = new int[n];
		parent = new int[n];
		this.n = n;
		makeSets();
	}
	//for making each node as a parent of itself
	void makeSets(){
		for(int i=0; i<n; i++){
			parent[i] = i;
		}
	}
	//find method using path compression
	int find(int x){
		if(parent[x]!=x){
			int super_parent = find(parent[x]);
			parent[x] = super_parent;
			return super_parent;
		}
		else
			return parent[x]; 
	}
	//Union method also using rank
	void union(int x, int y){
		int x_root = find(x);
		int y_root = find(y);

		if(x_root == y_root)
			return;

		if(rank[x_root]<rank[y_root]){
			parent[x_root] = y_root;
		}
		else if(rank[x_root]>rank[y_root])
			parent[y_root] = x_root;
		else{
			parent[y_root] = x_root;
			rank[x_root]++;
		}
	}
	public static void main(String[] args) {
		int n = 5; 
        DSU dsu = new DSU(n); 
  
        // 0 is a friend of 2 
        dsu.union(0, 2); 
  
        // 4 is a friend of 2 
        dsu.union(4, 2); 
  
        // 3 is a friend of 1 
        dsu.union(3, 1); 
  
        // Check if 4 is a friend of 0 
        if (dsu.find(4) == dsu.find(0)) 
            System.out.println("Yes"); 
        else
            System.out.println("No"); 
  
        // Check if 1 is a friend of 0 
        if (dsu.find(1) == dsu.find(0)) 
            System.out.println("Yes"); 
        else
            System.out.println("No"); 
	}
}