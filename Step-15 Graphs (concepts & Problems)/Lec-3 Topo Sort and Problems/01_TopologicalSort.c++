// Topological Sort Algorithm (using DFS) in DAG


/* // Problem-Link->   https://www.naukri.com/code360/problems/topological-sort_982938


#include <bits/stdc++.h>

void dfs(int node, vector<bool>& vis, vector<vector<int>>& adj, stack<int>& st) {
    vis[node] = 1;

    for(auto it : adj[node]) {
        if(!vis[it]) dfs(it, vis, adj, st);
    }

    st.push(node);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here

    vector<vector<int>> adj(v+1);

    for(int i=0; i < edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }

    vector<bool> vis(v, false);
    stack<int> st;

    for(int i=0; i < v; i++) {
        if(!vis[i]) {
            dfs(i, vis, adj, st);
        }
    }

    vector<int> ans;
    while(!st.empty()) {
        ans.push_back(st.top());
        st.pop();
    }

    return ans;
}

*/



#include<bits/stdc++.h>
using namespace std;


void dfs(int node, int vis[], vector<int> adj[], stack<int>& st) {
	vis[node] = 1;
	for(auto it : adj[node]) {
		if(!vis[it]) {
			dfs(it, vis, adj, st);
		}
	}
	st.push(node);
}


vector<int> topoSort(int V, vector<int> adj[]) {
	int vis[V] = {0};

	stack<int> st;
	for(int i=0; i < V; i++) {
		if(!vis[i]) {
			dfs(i, vis, adj, st);
		}
	}

	vector<int> ans;
	while(!st.empty()) {
		ans.push_back(st.top());
		st.pop();
	}

	return ans;
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
