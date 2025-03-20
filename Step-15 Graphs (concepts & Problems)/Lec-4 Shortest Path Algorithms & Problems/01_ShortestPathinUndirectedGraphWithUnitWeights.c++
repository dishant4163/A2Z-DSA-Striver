// Shortest Path in Undirected Graph with Unit Distance


/*// Problem-Link-> https://www.naukri.com/code360/problems/shortest-path-in-an-unweighted-graph_981297


vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t) {
	// Step-1 create adjaceny list
	vector<int> adj[n+1];
	for(auto it : edges) {
		adj[it.first].push_back(it.second);
		adj[it.second].push_back(it.first);
	}

	//Step-2 Decalre distance & parent
	vector<int> dist(n+1, 1e9);
	vector<int> parent(n+1, -1);
	dist[s] = 0;

	//step-3 Apply BFS to find shortest path
	queue<int> q;
	q.push(s);

	while(!q.empty()) {
		int node = q.front();
		q.pop();

		for(auto it : adj[node]) {
			if(dist[it] == 1e9) { // if not visited yet
			    dist[it] = dist[node] + 1;
				parent[it] = node;
				q.push(it);
			}
		}
	}

	//Step-4 Reconstruct the path from S to T using parent
	vector<int> path;
	for(int i=t; i != -1; i = parent[i]) {
		path.push_back(i);
	}

	//if there's is no path from S to T
	if(path.back() != s) return {}; // no path found

	//Step-5 Reverse the path to get it from S to T
	reverse(path.begin(), path.end());

	return path;
}


*/


#include<bits/stdc++.h>
using namespace std;


vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src) {
    vector<int> adj[N];
    for(auto it : edges) {
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }

    int dist[N];
    for(int i=0; i < N; i++) dist[i] = 1e9;

    //BFS 
    dist[src] = 0;
    queue<int> q;
    q.push(src);

    while(!q.empty()) {
        int node = q.front();
        q.pop();

        for(auto it : adj[node]) {
            // 1 is unit weight
            if(dist[node] + 1 < dist[it]) {
                dist[it] = 1 + dist[node];
                q.push(it);
            }
        }
    }

    vector<int> ans(N, -1);
    for(int i=0; i < N; i++) {
        if(dist[i] != 1e9) {
            ans[i] = dist[i];
        }
    }

    return ans;
}


int main(){

    int N=9, M=10;
    vector<vector<int>> edges= {{0,1},{0,3},{3,4},{4,5},{5,6},{1,2},{2,6},{6,7},{7,8},{6,8}};

    vector<int> ans = shortestPath(edges,N,M,0);
    cout << "The output is: " << endl;
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }


    return 0;
}
