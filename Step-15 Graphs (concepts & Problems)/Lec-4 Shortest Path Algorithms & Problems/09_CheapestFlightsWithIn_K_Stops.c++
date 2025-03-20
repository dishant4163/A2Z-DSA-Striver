// Cheapest Flights with in K Stops


/* // Problem-Link-> https://www.naukri.com/code360/problems/saving-money_1171195    


int savingMoney(int n, int source, int destination, int K, vector<vector<int>> &trains) {
    // Write your code here
    vector<pair<int, int>> adj[n];
    for(auto it : trains) {
        adj[it[0]].push_back({it[1], it[2]});
    }

    queue<pair<int, pair<int, int>>>q;
    q.push({0, {source, 0}}); // {stops, {node, cost}};

    vector<int> dist(n, INT_MAX);
    dist[source] = 0;

    while(!q.empty()) {
        int stops = q.front().first;
        int node = q.front().second.first;
        int cost = q.front().second.second;
        q.pop();

        if(stops > K) continue;

        for(auto it : adj[node]) {
            int adjNode = it.first;
            int edgeWt = it.second;

            if(cost + edgeWt < dist[adjNode] && stops <= K) {
                dist[adjNode] = cost + edgeWt;
                q.push({stops + 1, {adjNode, cost + edgeWt}});
            }
        }
    }

    if(dist[destination] == INT_MAX) return -1;
    return dist[destination];
}

*/



#include<bits/stdc++.h>
using namespace std;


int CheapestFLight(int n, vector<vector<int>> &flights, int src, int dest, int K) {
    vector<pair<int, int>> adj[n];
    for(auto it : flights) {
        adj[it[0]].push_back({it[1], it[2]});
    }

    queue<pair<int, pair<int, int>>> q;
    q.push({0, {src, 0}}); // {stops, {node, cost}}

    vector<int> dist(n, 1e9);
    dist[src] = 0;

    while(!q.empty()) {
        int stops = q.front().first;
        int node = q.front().second.first;
        int cost = q.front().second.second;
        q.pop();

        if(stops > K) continue;

        for(auto it : adj[node]) {
            int adjNode = it.first;
            int edgeWt = it.second;

            if(cost + edgeWt < dist[adjNode] && stops <= K) {
                dist[adjNode] = cost + edgeWt;
                q.push({stops + 1, {adjNode, cost+edgeWt}});
            }
        }
    }

    if(dist[dest] == 1e9) return -1;
    return dist[dest];
}



int main() {

    int n = 4, src = 0, dst = 3, K = 1;

    vector<vector<int>> flights = {{0, 1, 100}, {1, 2, 100}, {2, 0, 100}, {1, 3, 600},
    {2, 3, 200}};

    int ans = CheapestFLight(n, flights, src, dst, K);

    cout << "The cheapest flights within" << K  << " stops is: " << ans;
    cout << endl;


    return 0;
}
