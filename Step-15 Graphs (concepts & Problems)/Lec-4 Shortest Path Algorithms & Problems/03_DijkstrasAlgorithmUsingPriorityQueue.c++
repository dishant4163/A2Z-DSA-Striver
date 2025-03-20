// Dijkstra's Algorithm using Priority Queue



/* // Problem-Link-> https://www.naukri.com/code360/problems/dijkstra-s-shortest-path_920469


#include <bits/stdc++.h>

// Solve Using Priority-Queue
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {

    vector<int> miniDist(vertices, INT_MAX);
    miniDist[source] = 0;

    // Create an adjacency list from the edge list
    vector<vector<pair<int, int>>> adj(vertices);
    for (int i = 0; i < edges; i++) {
        int u = vec[i][0];    // source vertex
        int v = vec[i][1];    // destination vertex
        int weight = vec[i][2]; // edge weight
        
        adj[u].push_back({v, weight});  // add edge u -> v
        adj[v].push_back({u, weight});  // add edge v -> u (if the graph is undirected)
    }

    priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int>> > pq;
    pq.push({0, source}); // {minidist, src}


    while(!pq.empty()) { // Perform Dijkstra's algorithm
        int dist = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        // If the distance is already larger than 
        // the currently known shortest distance, skip it
        if(dist > miniDist[node]) continue;

        for(auto it : adj[node]) {
            int adjNode = it.first;
            int edgeWeight = it.second;

            // Relax the edge (update the distance if a shorter path is found)
            if(dist + edgeWeight < miniDist[adjNode]) {
                miniDist[adjNode] = dist + edgeWeight;
                pq.push({miniDist[adjNode], adjNode});
            }
        }
    }

    return miniDist;
}


*/



#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;


vector<int> dijkstra(int V, vector<vector<int>> adj[], int S) {
    priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int,int>> > pq;
    vector<int> miniDist(V);
    for(int i=0; i < V; i++) miniDist[i] = 1e9;

    miniDist[S] = 0;
    pq.push({0, S}); // (miniDist, srcNode)

    while(!pq.empty()) {
        int dist = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for(auto it : adj[node]) {
            int adjNode = it[0];
            int edgeWeight = it[1];

            if(dist + edgeWeight < miniDist[adjNode]) {
                miniDist[adjNode] = dist + edgeWeight;
                pq.push({miniDist[adjNode], adjNode});
            }
        }
    }

    return miniDist;
}



int main() {

    int V = 3, E = 3, S = 2;
    vector<vector<int>> adj[V];
    vector<vector<int>> edges;
    vector<int> v1{1, 1}, v2{2, 6}, v3{2, 3}, v4{0, 1}, v5{1, 3}, v6{0, 6};
    int i = 0;
    adj[0].push_back(v1);
    adj[0].push_back(v2);
    adj[1].push_back(v3);
    adj[1].push_back(v4);
    adj[2].push_back(v5);
    adj[2].push_back(v6);

    vector<int> res = dijkstra(V, adj, S);
    cout << "The output is: ";
    for (int i = 0; i < V; i++) {
        cout << res[i] << " ";
    }
    cout << endl;


    return 0;
}
