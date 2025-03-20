// Detect cycle in a directed graph (using BFS)


/* //Problem-Link(Detect cycle in a directed graph (using BFS))->  https://www.naukri.com/code360/problems/detect-cycle-in-a-directed-graph_1062626


#include<queue>

int detectCycleInDirectedGraph(int n, vector<pair<int, int>> &edges) {
    // Write your code here.
    vector<vector<int>> adj(n);

    for(int i=0; i < edges.size(); i++) {
        int u = edges[i].first - 1;
        int v = edges[i].second - 1;

        adj[u].push_back(v);
    }

    vector<int> indegree(n, 0);
    for(int i = 0; i < n; i++) {
        for (auto it : adj[i]) {
            indegree[it]++;
        }
    }

    queue<int> q;
    for(int i=0; i < n; i++) {
        if(indegree[i] == 0) {
            q.push(i);
        }
    }

    int count = 0;
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        count++;

        for(auto it : adj[node]) {
            indegree[it]--;
            if(indegree[it] == 0) q.push(it);
        }
    }

    if(count == n) return 0;
    return 1;
}

*/


#include<bits/stdc++.h>
using namespace std;


// Function to detect cycle in a directed graph.
bool isCyclic(int V, vector<int> adj[]) {
    int indegree[V] = {0};
    for(int i=0; i < V; i++) {
        for(auto it : adj[i]) {
            indegree[it]++;
        }
    }

    queue<int> q;
    for(int i=0; i < V; i++) {
        if(indegree[i] == 0) q.push(i);
    }

    int count = 0;
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        count++;

        for(auto it: adj[node]) {
            indegree[it]--;
            if(indegree[it] == 0) q.push(it);
        }
    }

    if(count == V) return false;

    return true;
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

