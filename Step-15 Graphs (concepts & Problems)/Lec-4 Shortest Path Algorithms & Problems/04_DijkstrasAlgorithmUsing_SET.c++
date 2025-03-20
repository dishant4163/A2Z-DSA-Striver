// Dijkstra's Algorithm using Set Data Structure


/* // Problem-Link-> https://www.naukri.com/code360/problems/dijkstra-s-shortest-path_920469


#include<bits/stdc++.h>

// Solve using Set
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

    set<pair<int, int>> st;
    st.insert({0, source});

    while(!st.empty()) {
        auto it = *(st.begin());
        int dist = it.first;
        int node = it.second;
        st.erase(it);

        // If the distance is already larger than 
        // the currently known shortest distance, skip it
        if(dist > miniDist[node]) continue;

        for(auto it : adj[node]){
            int adjNode = it.first;
            int edgeWt = it.second;

            if(dist + edgeWt < miniDist[adjNode]) {
                // erase if it already exists
                if(miniDist[adjNode] != INT_MAX) {
                    st.erase({miniDist[adjNode], adjNode});
                }

                miniDist[adjNode] = dist + edgeWt;
                st.insert({miniDist[adjNode], adjNode});
            }
        }
    }


    return miniDist;
}


*/



#include<bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int V, vector<vector<int>> adj[], int S) {
    set<pair<int, int>> st;
    st.insert({0, S});

    vector<int> miniDist(V, 1e9);
    miniDist[S] = 0;

    while(!st.empty()) {
        auto it = *(st.begin());
        int dist = it.first;
        int node = it.second;
        st.erase(it);

        for(auto it : adj[node]) {
            int adjNode = it[0];
            int edgeWt = it[1];

            if(dist + edgeWt < miniDist[adjNode]) {
                // erase if it already visited previously at a greater cost.
                if(miniDist[adjNode] != 1e9) {
                    st.erase({miniDist[adjNode], adjNode});
                }

                miniDist[adjNode] = dist + edgeWt;
                st.insert({miniDist[adjNode], adjNode});
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
