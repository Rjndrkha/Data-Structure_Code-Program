/* Minimum Cost Path using Dijkstra’s shortest path
algorithm with Min Heap by dinglizeng */
#include <stdio.h>
#include <queue>
#include <limits.h>
using namespace std;

/* define the number of rows and the number of columns */
#define R 4
#define C 5

/* 8 possible moves */
int dx[] = {1,-1, 0, 0, 1, 1,-1,-1};
int dy[] = {0, 0, 1,-1, 1,-1, 1,-1};

/* The data structure to store the coordinates of \\
the unit square and the cost of path from the top left. */
struct Cell{
	int x;
	int y;
	int cost;
};

/* The compare class to be used by a Min Heap.
* The greater than condition is used as this
is for a Min Heap based on priority_queue.
*/
class mycomparison
{
public:
bool operator() (const Cell &lhs, const Cell &rhs) const
{
	return (lhs.cost > rhs.cost);
}
};

/* To verify whether a move is within the boundary. */
bool isSafe(int x, int y){
	return x >= 0 && x < R && y >= 0 && y < C;
}

/* This solution is based on Dijkstra’s shortest path algorithm
* For each unit square being visited, we examine all
	possible next moves in 8 directions,
* calculate the accumulated cost of path for each
	next move, adjust the cost of path of the adjacent
	units to the minimum as needed.
* then add the valid next moves into a Min Heap.
* The Min Heap pops out the next move with the minimum
accumulated cost of path.
* Once the iteration reaches the last unit at the lower
right corner, the minimum cost path will be returned.
*/
int minCost(int cost[R][C], int m, int n) {

	/* the array to store the accumulated cost
	of path from top left corner */
	int dp[R][C];

	/* the array to record whether a unit
	square has been visited */
	bool visited[R][C];
	
	/* Initialize these two arrays, set path cost
	to maximum integer value, each unit as not visited */
	for(int i = 0; i < R; i++) {
		for(int j = 0; j < C; j++) {
			dp[i][j] = INT_MAX;
			visited[i][j] = false;
		}
	}
	
	/* Define a reverse priority queue.
	* Priority queue is a heap based implementation.
	* The default behavior of a priority queue is
		to have the maximum element at the top.
	* The compare class is used in the definition of the Min Heap.
	*/
	priority_queue<Cell, vector<Cell>, mycomparison> pq;
	
	/* initialize the starting top left unit with the
	cost and add it to the queue as the first move. */
	dp[0][0] = cost[0][0];
	pq.push({0, 0, cost[0][0]});
	
	while(!pq.empty()) {

		/* pop a move from the queue, ignore the units
		already visited */
		Cell cell = pq.top();
		pq.pop();
		int x = cell.x;
		int y = cell.y;
		if(visited[x][y]) continue;

		/* mark the current unit as visited */
		visited[x][y] = true;

		/* examine all non-visited adjacent units in 8 directions
		* calculate the accumulated cost of path for
		each next move from this unit,
		* adjust the cost of path for each next adjacent
		units to the minimum if possible.
		*/
		for(int i = 0; i < 8; i++) {
			int next_x = x + dx[i];
			int next_y = y + dy[i];
			if(isSafe(next_x, next_y) && !visited[next_x][next_y]) {
				dp[next_x][next_y] = min(dp[next_x][next_y],
				dp[x][y] + cost[next_x][next_y]);
				pq.push({next_x, next_y, dp[next_x][next_y]});
			}
		}
	}

	/* return the minimum cost path at the lower
	right corner */
	return dp[m][n];	
}

/* Driver program to test above functions */
int main()
{
int cost[R][C] = { {1, 8, 8, 1, 5},
					{4, 1, 1, 8, 1},
					{4, 2, 8, 8, 1},
					{1, 5, 8, 8, 1} };
printf(" %d ", minCost(cost, 3, 4));
return 0;
}
