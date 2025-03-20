// Bellman Ford Algorithm


/*// Problem-Link->  https://www.naukri.com/code360/problems/bellmon-ford_2041977


vector<int> bellmonFord(int n, int m, int src, vector<vector<int>> &edges) {
    // Write your code here.
    vector<int> dist(n + 1, 1e8);
    dist[src] = 0;

    for(int i=1; i < n; i++) {
        for(int j=0; j < m; j++) {
            int u = edges[j][0];
            int v = edges[j][1];
            int wt = edges[j][2];

            if(dist[u] + wt < dist[v]) {
                dist[v] = wt + dist[u];
            }
        }
    }

    return dist;
}

*/




#include<bits/stdc++.h>
using namespace std;

/*  Function to implement Bellman Ford
*   edges: vector of vectors which represents the graph
*   S: source vertex to start traversing graph with
*   V: number of vertices
*/

vector<int> bellmanFord(int V, vector<vector<int>>& edges, int S) {
    vector<int> dist(V, 1e8);
    dist[S] = 0;
    // do (N-1) times relaxation
    for(int i = 0; i < V-1; i++) {
        for(auto it : edges) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            if(dist[u] != 1e8 && dist[u] + wt < dist[v]) {
                dist[v] = dist[u] + wt;
            }
        }
    }

    // it is gievn that question have -ve cycle
    // Nth relaxation to check negative cycle
    for(auto it : edges) {
        int u = it[0];
            int v = it[1];
            int wt = it[2];
            if(dist[u] != 1e8 && dist[u] + wt < dist[v]) return {-1};
    }


    return dist;
}



int main() {

    int V = 6;
	vector<vector<int>> edges(7, vector<int>(3));
	edges[0] = {3, 2, 6};
	edges[1] = {5, 3, 1};
	edges[2] = {0, 1, 5};
	edges[3] = {1, 5, -3};
	edges[4] = {1, 2, -2};
	edges[5] = {3, 4, -2};
	edges[6] = {2, 4, 3};

	int S = 0;

	vector<int> dist = bellmanFord(V, edges, S);
    cout << "The output is: ";
	for (auto d : dist) {
		cout << d << " ";
	}
	cout << endl;





    return 0;
}
