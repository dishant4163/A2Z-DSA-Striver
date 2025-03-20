// Strongly Connected Components - Kosaraju's Algorithm



/*// Problem-Link-> https://www.naukri.com/code360/problems/count-strongly-connected-components-kosaraju-s-algorithm_1171151


#include<bits/stdc++.h>

void dfs(int node, vector<int>& vis, vector<int> adj[], stack<int>& st) {
	vis[node] = 1;
	for(auto it : adj[node]) {
		if(!vis[it]) {
			dfs(it, vis, adj, st);
		}
	}
	st.push(node);
}

void dfs2(int node, vector<int>& vis, vector<int> adjT[]) {
	vis[node] = 1;
	for(auto it : adjT[node]) {
		if(!vis[it]) {
			dfs2(it, vis, adjT);
		}
	}
}


int stronglyConnectedComponents(int v, vector<vector<int>> &edges){
	// Write your code here.
	vector<int> adj[v];
	for(auto it : edges) {
		adj[it[0]].push_back(it[1]);
	}

	vector<int> vis(v, 0);
	stack<int> st;
	for(int i = 0; i < v; i++) {
		if(!vis[i]) {
			dfs(i, vis, adj, st);
		}
	}

	vector<int> adjT[v];
	for(int i = 0; i < v; i++) {
		vis[i] = 0; // mark unvisited again
		for(auto it : adj[i]) {
			adjT[it].push_back(i);
		}
	}

	int scc = 0;
	while(!st.empty()) {
		int node = st.top();
		st.pop();
		if(!vis[node]) {
			scc++;
			dfs2(node, vis, adjT);
		}
	}

	return scc;
}

*/





#include<bits/stdc++.h>
using namespace std;


void dfs(int node, vector<int>& vis, vector<int> adj[], stack<int>& st) {
    vis[node] = 1;
    for(auto it : adj[node]) {
        if(!vis[it]) {
            dfs(it, vis, adj, st);
        }
    }

    st.push(node);
}


void dfs2(int node, vector<int>& vis, vector<int> adjT[]) {
    vis[node] = 1;
    for(auto it : adjT[node]) {
        if(!vis[it]) {
            dfs2(it, vis, adjT);
        }
    }
}



//Function to find number of strongly connected components in the graph.
int kosaraju(int V, vector<int> adj[]) {
    vector<int> vis(V, 0);
    stack<int> st; // stroing nodes acc. to finishing time
    for(int i=0; i < V; i++) {
        if(!vis[i]) {
            dfs(i, vis, adj, st);
        }
    }

    //Step-2 revrse the graph
    vector<int> adjT[V];
    for(int i=0; i < V; i++) {
        // mark every visited nodes as UNVISITED
        vis[i] = 0;
        for(auto it : adj[i]) {
            // in normal graph  we go from edge i -> it
            // & in reverse graph we go edge it -> i
            adjT[it].push_back(i);
        }
    }

    //Step-3 dfd traversal acc. to finishing time
    int scc = 0;
    while(!st.empty()) {
        int node = st.top();
        st.pop();
        if(!vis[node]) {
            scc++;
            dfs2(node, vis, adjT);
        }
    }

    return scc; // return no. of scc nodes
}



int main() {

    int n = 5;
    int edges[5][2] = {
        {1, 0}, {0, 2},
        {2, 1}, {0, 3},
        {3, 4}
    };
    vector<int> adj[n];
    for (int i = 0; i < n; i++) {
        adj[edges[i][0]].push_back(edges[i][1]);
    }

    int ans = kosaraju(n, adj);
    cout << "The number of strongly connected components is: " << ans << endl;


    return 0;
}
