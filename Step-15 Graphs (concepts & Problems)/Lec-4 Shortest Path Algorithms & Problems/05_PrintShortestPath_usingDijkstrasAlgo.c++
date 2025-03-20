// Print Shortest Path - Dijkstra’s Algorithm





#include<bits/stdc++.h>
using namespace std;


vector<int> shortestPath(int n, int m, vector<vector<int>> &edges) {
    vector<pair<int, int>> adj[n + 1];
    for(auto it : edges) {
        adj[it[0]].push_back({it[1], it[2]});
        adj[it[1]].push_back({it[0], it[2]});
    }

    priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;
    pq.push({0, 1});

    vector<int> dist(n+1, 1e9), parent(n+1);
    for(int i = 1; i <= n; i++) parent[i] = i;

    dist[1] = 0; //mark source node as 0
    while(!pq.empty()) {
        auto it = pq.top();
        int dis = it.first;
        int node = it.second;
        pq.pop();

        for(auto it : adj[node]) {
            int adjNode = it.first;
            int edgeWt = it.second;

            if(dis + edgeWt < dist[adjNode]) {
                dist[adjNode] = dis + edgeWt;
                pq.push({dis + edgeWt, adjNode});
                parent[adjNode] = node;
            }
        }
    }

    if(dist[n] == 1e9) return {-1};

    vector<int> path;
    int node = n; // assign the last nth-node
    // Start backtring to the the path from n to 2 & we have to add
    // 1st node as manually & we get answer in reverse order due to backtracking
    while(parent[node] != node) {
        path.push_back(node);
        node = parent[node];
    }
    // manually add 1 i.e, source node in path answer
    path.push_back(1);
    // Reverse the ans to get in correct order 
    reverse(path.begin(), path.end());

    return path;
}



int main() {

    int V = 5, E = 6;
    vector<vector<int>> edges = {{1, 2, 2}, {2, 5, 5}, {2, 3, 4}, {1, 4, 1}, {4, 3, 3}, 
    {3, 5, 1}};

    vector<int> path = shortestPath(V, E, edges);
    cout << "The output is: ";
    for (int i = 0; i < path.size(); i++) {
        cout << path[i] << " ";
    }
    cout << endl;


    return 0;
}
