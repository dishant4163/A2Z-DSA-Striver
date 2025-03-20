// Detect cycle in a directed graph (using DFS)

/* //Problem-Link(Detect cycle in a directed graph (using DFS))->  https://www.naukri.com/code360/problems/detect-cycle-in-a-directed-graph_1062626


// Solve using DFS
bool dfsCycle(int node, vector<int>& vis, vector<int>& pathVis, vector<vector<int>>& adj) {
    vis[node] = true;
    pathVis[node] = true;

    for(auto it : adj[node]) {
        if (!vis[it]) {
            if (dfsCycle(it, vis, pathVis, adj)) return true;
        }
        else if (pathVis[it]) return true;
    }

    //Backtrack
    pathVis[node] = false;
    return false;
}


int detectCycleInDirectedGraph(int n, vector<pair<int, int>> &edges) {
    // Write your code here.
    vector<vector<int>> adj(n);

    for(int i=0; i < edges.size(); i++) {
        int u = edges[i].first - 1;  // Adjust for 0-based index
        int v = edges[i].second - 1; // Adjust for 0-based index

        adj[u].push_back(v);
    }

    vector<int> vis(n, 0);
    vector<int> pathVis(n, 0);

    for(int i=0; i < n; i++) {
        if(!vis[i]) {
            if(dfsCycle(i, vis, pathVis, adj)) {
                return true;
            }
        }
    }

    return false;
}

*/



#include<iostream>
#include<vector>

using namespace std;


bool dfsCheck(int node, vector<int> adj[], int vis[], int pathVis[]) {
	vis[node] = 1;
	pathVis[node] = 1;

	for(auto it: adj[node]) {
		if(!vis[it]) {
			if(dfsCheck(it, adj, vis, pathVis) == true) return true;
		}

		// if the node has been previously visited
		// but it has to be visited on the same path
		else if (pathVis[it]) return true;
	}

	pathVis[node] = 0; // backtracking

	return false;
}


// Function to detect cycle in a directed graph.
bool isCyclic(int V, vector<int> adj[]) {
    int vis[V] = {0};
	int pathVis[V] = {0};

	for(int i=0; i < V; i++) {
		if(!vis[i]) {
			if(dfsCheck(i, adj, vis, pathVis) == true) return true;
		}
	}

	return false;
}


int main() {

    // V = 11, E = 11;
	vector<int> adj[11] = {{}, {2}, {3}, {4, 7}, {5}, {6}, {}, {5}, {9}, {10}, {8}};
	int V = 11;

	bool ans = isCyclic(V, adj);

	if (ans)
		cout << "True\n";
	else
		cout << "False\n";


    return 0;
}
