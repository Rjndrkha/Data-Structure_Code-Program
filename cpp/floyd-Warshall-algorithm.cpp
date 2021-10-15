
#include <bits/stdc++.h>
using namespace std;
#define INF 100000
int v;
void floydWarshall(vector<vector<int>>&graph)
{
    int dist[v][v], i, j, k;
    for (i = 0; i < v; i++)
        for (j = 0; j < v; j++)
            dist[i][j] = graph[i][j];

    for (k = 0; k < v; k++) {
        for (i = 0; i < v; i++) {
            for (j = 0; j < v; j++) {
                if (dist[i][j] > (dist[i][k] + dist[k][j])
                    && (dist[k][j] != INF
                        && dist[i][k] != INF))
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
     for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            if (dist[i][j] == INF)
                cout << "INF ";
            else
                cout << dist[i][j] << "  ";
        }
        cout << endl;
    }
}
int main()
{
    cin>>v;
    vector<vector<int>>graph(v,vector<int>(v,0));
    for(int i=0;i<v;i++)
    {
        for(int j=0;j<v;j++)
        {
            //if path not possible then pass value 100000(INF)
            cin>>graph[i][j];
        }
    }
    floydWarshall(graph);
    return 0;
}
