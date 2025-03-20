// Shortest Path in Directed Acyclic Graph Topological Sort


/* // Problem-Link-> https://www.naukri.com/code360/problems/shortest-path-in-dag_8381897


void dfs(int node, int vis[], vector<pair<int, int>> adj[], stack<int>& st) {
    vis[node] = 1;

    for(auto it : adj[node]) {
        int v = it.first;
        if(!vis[v]) {
            dfs(v, vis, adj, st);
        }
    }

    st.push(node);
}

vector<int> shortestPathInDAG(int n, int m, vector<vector<int>> &edges) {
    // Write your code here
    vector<pair<int, int>> adj[n];
    for(int i=0; i < m; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];
        adj[u].push_back({v, wt});
    }

    int vis[n] = {0};
    stack<int> st;
    for(int i=0; i < n; i++) {
        if(!vis[i]) {
            dfs(i, vis, adj, st);
        }
    }

    vector<int> dist(n);
    for(int i=0; i < n; i++) {
        dist[i] = 1e9;
    } 
    dist[0] = 0;

    while(!st.empty()) {
        int node = st.top();
        st.pop();

        for(auto it : adj[node]) {
            int v = it.first;
            int wt = it.second;

            if(dist[node] + wt < dist[v]) {
                dist[v] = wt + dist[node];
            }
        }
    }

    for(int i=0; i < n; i++) {
        if(dist[i] == 1e9) dist[i] = -1;
    }

    return dist;
}


*/


#include<bits/stdc++.h>
using namespace std;


void dfsTopoSort(int node, vector<pair<int, int>> adj[], int vis[], stack<int>& st) {
    vis[node] = 1;

    for(auto it : adj[node]) {
        int v = it.first;
        if(!vis[v]) {
            dfsTopoSort(v, adj, vis, st);
        }
    }

    st.push(node);
}


vector<int> shortestPath(int N, int M, vector<vector<int>>& edges) {
    // N= number of vertices and M= number of edges
    vector<pair<int, int>> adj[N];
    for(int i=0; i < M; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];
        adj[u].push_back({v, wt});
    }

    //Step-1 find the topo sort
    int vis[N] = {0};
    stack<int> st;
    for(int i=0; i < N; i++) {
        if(!vis[i]) {
            dfsTopoSort(i, adj, vis, st);
        }
    }

    //Step-2 Do the distance 
    vector<int> dist(N);
    for(int i=0; i < N; i++) dist[i] = 1e9;
    dist[0] = 0; // mark source as zero
    while(!st.empty()) {
        int node = st.top();
        st.pop();

        for(auto it : adj[node]) {
            int v = it.first;
            int wt = it.second;

            if(dist[node] + wt < dist[v]) {
                dist[v] = dist[node] + wt;
            }
        }
    }

    for(int i=0; i < N; i++) {
        if(dist[i] == 1e9) dist[i] = -1;
    }

    return dist;
}



int main() {

    int N = 6, M = 7;

    vector<vector<int>> edges= {{0,1,2},{0,4,1},{4,5,4},{4,2,2},{1,2,3},{2,3,6},{5,3,1}};

    vector < int > ans = shortestPath(N, M, edges);
    cout << "The output is: " ;
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }


    return 0;
}
