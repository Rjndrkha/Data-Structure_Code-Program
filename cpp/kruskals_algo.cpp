#include <bits/stdc++.h>
using namespace std;
#define ll long long int
void init() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

}

class DSU {
    ll *parent;
    ll *rank;
public:
    DSU(ll V) {
        parent = new ll[V];
        rank = new ll[V];

        // initially all the vertex are their own parent
        // And rank = 1
        for (int i = 0; i < V; i++) {
            parent[i] = i;
            rank[i] = 1;
        }
    }

    // Find
    ll find(ll x) {
        if (parent[x] == x) {
            return x;
        }
        parent[x] = find(parent[x]);
        return parent[x];
    }

    // Unite (Union)
    void unite(ll x, ll y) {
        // find the set in which x and y belong
        ll s1 = find(x);
        ll s2 = find(y);

        // if they does not belong to the same set
        if (s1 != s2) {
            if (rank[s1] > rank[s2]) {
                parent[s2] = s1;
                rank[s1] += rank[s2];
            } else {
                parent[s1] = s2;
                rank[s2] += rank[s1];
            }
        }
    }
};

class Graph {
    ll V;
    vector<vector<ll>> edgeList;
public:
    Graph(ll V) {
        this->V = V;
    }

    void addEdge(ll x, ll y, ll w) {
        edgeList.push_back({w, x, y});
    }

    ll kruskals_mst() {
        // Main Logic
        // Sort all the edges based upon their weight. As weight is in 0 index. By default sort func sorts the vector based on 0 index.
        sort(edgeList.begin(), edgeList.end());

        // Init a DSU
        DSU dsu(V);

        ll min_wt = 0;
        for (auto edge : edgeList) {
            ll wt = edge[0];
            ll x = edge[1];
            ll y = edge[2];

            // if x and y belong to different set, unite them else discard the edge
            // take the min edge from the edgeList that does not forms a cycle.
            if (dsu.find(x) != dsu.find(y)) {
                dsu.unite(x, y);
                min_wt += wt;
            }
        }
        return min_wt;
    }
};

int main() {
    // init();
    ll V, E;
    cin >> V >> E;
    Graph g(V);
    for (int i = 0; i < E; i++) {
        ll x, y, wt;
        cin >> x >> y >> wt;
        g.addEdge(x - 1, y - 1, wt);
    }

    cout << g.kruskals_mst() << endl;

    return 0;
}
