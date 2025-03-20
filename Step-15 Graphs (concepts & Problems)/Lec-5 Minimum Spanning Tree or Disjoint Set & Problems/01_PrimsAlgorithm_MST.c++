// Prim's Algorithm - Minimum Spanning Tree


/*// https://www.naukri.com/code360/problems/prim-s-mst_1095633


#include <bits/stdc++.h> 
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g) {
    // Write your code here.
    vector<pair<pair<int,int>, int>> ansMST; //Result vector to store the MST edges
    vector<pair<int, int>> adj[n + 1]; // Adjacency list representation of the graph

    for(auto it : g) {
        int u = it.first.first;
        int v = it.first.second;
        int wt = it.second;

        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    pq.push({0, {1, -1}}); // {weight, {node, parent}}

    vector<int> vis(n+1, 0); // Visited array to keep track of visited nodes

    // Process the graph using Prim's algorithm
    while(!pq.empty()) {
        int wt = pq.top().first;
        int node = pq.top().second.first;
        int parent = pq.top().second.second;
        pq.pop();

        // Skip the node if it's already visited
        if(vis[node]) continue;
        vis[node] = 1;

        // If parent is not -1, 
        // then this is an edge in the MST
        if(parent != -1) ansMST.push_back({{parent, node}, wt}); // {{parent, node}, wt} question want answer in this order 

        // Add the adjacent edges to the priority queue
        for(auto it : adj[node]) {
            int adjNode = it.first;
            int edgeWt = it.second;

            // Push the adjacent node to the queue if not visited
            if(!vis[adjNode]) {
                pq.push({edgeWt, {adjNode, node}});
            }
        }
    }

    return ansMST;
}


*/


#include<bits/stdc++.h>
using namespace std;


//Function to find sum of weights of edges of the Minimum Spanning Tree.
int spanningTree(int V, vector<vector<int>> adj[]) {
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int>> > pq;
	pq.push({0, 0}); // {wt, node}

	vector<int> vis(V, 0);
	int mstSum = 0;

	while(!pq.empty()) {
		int wt = pq.top().first;
		int node = pq.top().second;
		pq.pop();

		if(vis[node] == 1) continue;
		vis[node] = 1;

		mstSum += wt;

		for(auto it : adj[node]) {
			int adjNode = it[0];
			int edgeWt = it[1];

			if(!vis[adjNode]) {
				pq.push({edgeWt, adjNode});
			}
		}
	}

	return mstSum;
}



int main() {

    int V = 5;
	vector<vector<int>> edges = {{0, 1, 2}, {0, 2, 1}, {1, 2, 1}, {2, 3, 2}, {3, 4, 1}, {4, 2, 2}};
	vector<vector<int>> adj[V];
	for (auto it : edges) {
		vector<int> tmp(2);
		tmp[0] = it[1];
		tmp[1] = it[2];
		adj[it[0]].push_back(tmp);

		tmp[0] = it[0];
		tmp[1] = it[2];
		adj[it[1]].push_back(tmp);
	}

	int sum = spanningTree(V, adj);
	cout << "The sum of all the edge weights: " << sum << endl;


    return 0;
}
