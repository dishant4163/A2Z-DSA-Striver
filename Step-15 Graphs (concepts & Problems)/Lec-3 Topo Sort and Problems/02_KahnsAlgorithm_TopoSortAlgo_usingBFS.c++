// Kahn's Algorithm | Topological Sort Algorithm (using BFS) in DAG


/* // Problem-Link->   https://www.naukri.com/code360/problems/topological-sort_982938



// Kahn's Algorithm i.e., using BFS for Topological Sort

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e) {
    // Write your code here
    vector<vector<int>> adj(v); 

    for(int i=0; i < edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }

    vector<int> indegree(v, 0);
    for(int i=0; i < v; i++) {
        for(auto it : adj[i]){
            indegree[it]++;
        }
    }

    queue<int> q;
    for(int i=0; i < v; i++) {
        if(indegree[i] == 0) q.push(i);
    }

    vector<int> ansTopoSort;

    while(!q.empty()) {
        int node = q.front();
        q.pop();
        ansTopoSort.push_back(node);

        for(auto it : adj[node]) {
            indegree[it]--;
            if(indegree[it] == 0) q.push(it);
        }
    }

    return ansTopoSort;
}



*/



#include<bits/stdc++.h>
using namespace std;



//Function to return list containing vertices in Topological order.
vector<int> topoSort(int V, vector<int> adj[]) {
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

    vector<int> ansTopoSort;

    while(!q.empty()) {
        int node = q.front();
        q.pop();
        ansTopoSort.push_back(node);
        // node is in your topo sort so 
        // remove it from the indegree
        for(auto it : adj[node]) {
            indegree[it]--;
            if(indegree[it] == 0) q.push(it);
        }
    }

    return ansTopoSort;
}




int main() {

	//V = 6;
	vector<int> adj[6] = {{}, {}, {3}, {1}, {0, 1}, {0, 2}};
	int V = 6;

	vector<int> ans = topoSort(V, adj);

	for (auto node : ans) {
		cout << node << " ";
	}
	cout << endl;

	return 0;
}

