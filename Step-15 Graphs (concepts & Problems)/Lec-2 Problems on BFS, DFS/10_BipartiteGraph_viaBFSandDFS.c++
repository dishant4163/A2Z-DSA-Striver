// Bipartite Graph | BFS & DFS Implementation



// Directed Graph
/* // Problem-Link(DFS Implementation)->  https://www.naukri.com/code360/problems/check-graph-is-bipartite-or-not_920551


bool dfs(int node, int col, int colorAr[], vector<int> adj[]) {
	colorAr[node] = col;

	for(int it : adj[node]) {
		if(colorAr[it] == -1) {
			if(dfs(it, !col, colorAr, adj) == false) return false;
		}
		else if (colorAr[it] == col) return false;
	}

	return true;
}

bool isGraphBirpatite(vector<vector<int>> &edges) {
	// Write your code here.
	int v = edges.size();

	vector<int> adj[v];

	for(int i=0; i < v; i++) {
		for(int j=0; j < v; j++) {
			if(edges[i][j] == 1 && i != j) {
				adj[i].push_back(j);
				adj[j].push_back(i);
			}
		}
	}

	int colorAr[v];
	for(int i=0; i < v; i++) colorAr[i] = -1;

	for(int i=0; i < v; i++) {
		if(colorAr[i] == -1) {
			if(dfs(i, 0, colorAr, adj) == false) return false;
		}
	}

	return true;
}

*/


// Undirected Graph
/* // Problem-Link(BFS Implementation)->   https://www.naukri.com/code360/problems/is-bipartite_3849884


#include <bits/stdc++.h> 

bool bfs(int start, int v, int colorAr[], vector<int> adj[]) {
    colorAr[start] = 0;
    queue<int> q;
    q.push(start);

    while(!q.empty()) {
        int node = q.front();
        q.pop();

        for(auto it : adj[node]) {
            if(colorAr[it] == -1) {
                colorAr[it] = !colorAr[node];
                q.push(it);
            }
            else if(colorAr[it] == colorAr[node]) return false;
        }
    }

    return true;
}


bool isBipartite(int n, vector<vector<int>> &edges) {
    // Write your code here.
    vector<int> adj[n];
    // converting 2D-adjlist to adjlist
    for(auto edge : edges) {
        int u = edge[0], v = edge[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int colorAr[n];
    for(int i=0; i < n; i++) colorAr[i] = -1;

    for(int i=0; i < n; i++) {
        if(colorAr[i] == -1) {
            if(bfs(i, n, colorAr, adj) == false) return false;
        }
    }

    return true;
}

*/


// Undirected Graph
/* // Problem-Link(DFS Implementation)->   https://www.naukri.com/code360/problems/bipartite-graph_1062589


#include <bits/stdc++.h>

bool dfs(int node, int color, int colorAr[], vector<int>adj[]) {
	colorAr[node] = color;

	for(auto it : adj[node]) {
		if(colorAr[it] == -1) {
			if(dfs(it, !color, colorAr, adj) == false) return false;
		}
		else if (colorAr[it] == colorAr[node]) return false;
	}

	return true;
}


bool isBipartite(vector<vector<int>>& graph, int vertices, int edges) {
	// Write your code here
	vector<int> adj[vertices + 1]; // +1 due to 1-based indexing
    // converting 2D-adjlist to adjlist
    for(auto edge : graph) {
        int u = edge[0], v = edge[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int colorAr[vertices + 1]; // +1 due to 1-based indexing
    for(int i=0; i < vertices + 1; i++) colorAr[i] = -1;

    for(int i=0; i < vertices; i++) {
		if(colorAr[i] == -1) {
			if(dfs(i, 0, colorAr, adj) == false) return false;
		}
	}

    return true;
}

*/




#include<iostream>
#include<vector>
#include<queue>
using namespace std;


// BFS Implementation
bool bfs(int start, int V, vector<int> adj[], int color[]) {
	color[start] = 0;
	queue<int> q;
	q.push(start);

	while(!q.empty()) {
		int node = q.front();
		q.pop();

		for(auto it : adj[node]) {
			// if the adjacent node is yet not colored you will give
			// the opposite color of the node
			if(color[it] == -1) { // If the neighbor is not colored
				color[it] = !color[node]; // Assign opposite color
				q.push(it);
			}

			// is the adjacent guy having the same color someone did
			// color it on same other path
			else if (color[it] == color[node]) {
				return false;
			}
		}
	}

	return true;
}


bool isBipartite(int V, vector<int> adj[]) {
    int color[V];
	for(int i=0; i < V; i++) color[i]= -1;

	for(int i=0; i < V; i++) {
		if(color[i] == -1) {
			if(bfs(i, V, adj, color) == false) {
				return false;
			}
		}
	}

	return true;
}










// DFS Implementation
bool dfs(int node, int col, int colorAr[], vector<int> adj[]) {
	colorAr[node] = col;

	for(auto it : adj[node]) {
		if(colorAr[it] == 1) {
			if( dfs(it, !col, colorAr, adj) == false) return false;
		}
		else if (colorAr[it] == col) {
			return false;
		}
	}

	return true;
}


bool checkBipartite(int V, vector<int> adj[]) {
	int colorAr[V];
	for(int i=0; i < V; i++) colorAr[i] = -1;

	for(int i=0; i < V; i++) {
		if(colorAr[i] == -1) {
			if(dfs(i, 0, colorAr, adj) == false) return false;
		}
	}

	return true;
}







void addEdge(vector <int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main() {

    // V = 4, E = 4
	vector<int>adj[4];

	addEdge(adj, 0, 2);
    addEdge(adj, 0, 3);
	addEdge(adj, 2, 3);
	addEdge(adj, 3, 1);

cout << "Solve Using BFS Implementation" <<endl;
	bool ans = isBipartite(4, adj);    
	if(ans)cout << "Yes, graph is Bipartite\n";
	else cout << "Not Bipartit\n";


cout << endl << endl;

cout << "Solve Using DFS Implementation" <<endl;
    bool res = checkBipartite(4, adj);    
	if(res)cout << "Yes, graph is Bipartite\n";
	else cout << "Not Bipartit\n"; 


    return 0;
}
