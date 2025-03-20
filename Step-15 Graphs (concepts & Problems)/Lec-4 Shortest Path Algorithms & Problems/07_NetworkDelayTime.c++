// Network Delay Time


/* // Problem-Link-> https://www.naukri.com/code360/problems/network-delay-time_1382215


#include<bits/stdc++.h>

int networkDelayTime(vector<vector<int>> &edges, int n, int k) {
    // Write your code here.
    vector<pair<int, int>> adj[n + 1];
    for(auto it : edges) {
        int ui = it[0];
        int vi = it[1];
        int wi = it[2];

        adj[ui].push_back({wi, vi});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> >pq;
    pq.push({0, k});
    vector<int> dist(n+1, INT_MAX);
    dist[k] = 0;

    while(!pq.empty()) {
        int node = pq.top().second;
        pq.pop();

        for(auto it : adj[node]) {
            int adjNode = it.second;
            int wt = it.first;

            if(wt + dist[node] < dist[adjNode]) {
                dist[adjNode] = wt + dist[node];
                pq.push({wt + dist[node], adjNode});
            }
        }
    }

    int ans = 0;
    for(int i=1; i < dist.size(); i++) {
        ans = max(ans, dist[i]);
    }

    if(ans == INT_MAX) return -1;

    return ans;
}

*/



#include<bits/stdc++.h>
using namespace std;


int networkDelayTime(vector<vector<int>> &edges, int n, int k) {
    // Write your code here.
    vector<pair<int, int>> adj[n + 1];
    for(auto it : edges) {
        int ui = it[0];
        int vi = it[1];
        int wi = it[2];

        adj[ui].push_back({wi, vi});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> >pq;
    pq.push({0, k});
    vector<int> dist(n+1, INT_MAX);
    dist[k] = 0;

    while(!pq.empty()) {
        int node = pq.top().second;
        pq.pop();

        for(auto it : adj[node]) {
            int adjNode = it.second;
            int wt = it.first;

            if(wt + dist[node] < dist[adjNode]) {
                dist[adjNode] = wt + dist[node];
                pq.push({wt + dist[node], adjNode});
            }
        }
    }

    int ans = 0;
    for(int i=1; i < dist.size(); i++) {
        ans = max(ans, dist[i]);
    }

    if(ans == INT_MAX) return -1;

    return ans;
}


int main() {

    // Number of nodes (n) and starting node (k)
    int n = 4;  // 4 nodes
    int k = 2;  // Start from node 2
    
    // Edges of the graph
    vector<vector<int>> edges = {
        {2, 1, 1},  // Edge from node 2 to node 1 with weight 1
        {2, 3, 1},  // Edge from node 2 to node 3 with weight 1
        {3, 4, 1}   // Edge from node 3 to node 4 with weight 1
    };

    // Call the function to get the network delay time
    int result = networkDelayTime(edges, n, k);

    // Output the result
    if (result == -1) {
        cout << "Not all nodes can receive the signal." << endl;
    } else {
        cout << "The network delay time is: " << result << endl;
    }




    return 0;
}

