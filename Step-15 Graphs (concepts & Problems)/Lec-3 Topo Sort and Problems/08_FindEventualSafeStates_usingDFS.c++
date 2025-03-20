// Find Eventual Safe States using DFS


/* // Problem-Link-> https://www.naukri.com/code360/problems/safe-nodes-in-the-graph_1376703
// Solve using DFS


bool dfs(int node, vector<int> adj[], vector<int>& vis, vector<int>& pathVis, vector<int>& check) {
    vis[node] = 1;
    pathVis[node] = 1;
    check[node] = 0;

    for(auto it : adj[node]) {
        if(!vis[it]) {
            if(dfs(it, adj, vis, pathVis, check) == true) {
                check[node] = 0; // Not safe
                return true;
            }
        }
        else if(pathVis[it]) {
            check[node] = 0; // Node is part of a cycle
            return true;
        }
    }

    check[node] = 1; // Safe node
    pathVis[node] = 0; //Backtrack
    return false;
}


vector<int> safeNodes(vector<vector<int>> &edges, int n, int e) {
    // Write your code here.
    vector<int> adj[n+1];
    for(int i=0; i < edges.size(); i++) {
        adj[edges[i][0]].push_back(edges[i][1]);
    }

    vector<int> vis(n, 0), pathVis(n, 0), check(n, 0);
    for(int i=0; i < n; i++) {
        if(!vis[i]) {
            dfs(i, adj, vis, pathVis, check);
        }
    }

    vector<int> ans;
    for(int i=0; i < n; i++) {
        if(check[i] == 1) ans.push_back(i);
    }

    return ans;
}



*/




#include<bits/stdc++.h>
using namespace std;


bool dfs(int node, vector<int> adj[], int vis[], int pathVis[], int check[]) {
    vis[node] = 1;
    pathVis[node] = 1;
    check[node] = 0;

    for(auto it : adj[node]) {
        if(!vis[it]) {
            if(dfs(it, adj, vis, pathVis, check) == true) {
                check[node] = 0;
                return true;
            }
        }
        else if(pathVis[it]) {
            check[node] = 0;
            return true;
        }
    }

    check[node] = 1;
    pathVis[node] = 0;
    return false;
}


vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
    int vis[V] = {0};
    int pathVis[V] = {0};
    int check[V] = {0};

    for(int i=0; i < V; i++) {
        if(!vis[i]) {
            dfs(i, adj, vis, pathVis, check);
        }
    }

    vector<int> safeNodes;
    for(int i=0; i < V; i++) {
        if (check[i] == 1) safeNodes.push_back(i);
    }

    return safeNodes;
}



int main() {

    vector<int> adj[12] = {{1}, {2}, {3, 4}, {4, 5}, {6}, {6}, {7}, {}, {1, 9}, {10},
		{8}, {9}
	};
	int V = 12;

	vector<int> safeNodes = eventualSafeNodes(V, adj);
    cout << "Eventual Safe States are: ";
	for (auto node : safeNodes) {
		cout << node << " ";
	}
	cout << endl;


    return 0;
}
