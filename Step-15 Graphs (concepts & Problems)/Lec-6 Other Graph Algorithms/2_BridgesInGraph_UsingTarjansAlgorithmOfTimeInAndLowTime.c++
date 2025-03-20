// Bridges in Graph - Using Tarjan's Algorithm Of Time in and Low Time


/* // PRoblem-Link-> https://www.naukri.com/code360/problems/bridges-in-graph_893026


#include<bits/stdc++.h>

void dfs(int curNode, int parent, vector<int>& vis, vector<int> adj[], 
    int &timer, int tin[], int lowT[], vector<vector<int>>& bridges) {
    vis[curNode] = 1;
    tin[curNode] = lowT[curNode] = timer++;

    for(auto it : adj[curNode]) {
        if(it == parent) continue;

        if(vis[it] == 0) {
            dfs(it, curNode, vis, adj, timer, tin, lowT, bridges);
            lowT[curNode] = min(lowT[curNode], lowT[it]);
            // check this current-Node with 'it' forms a bridges or not
            if(lowT[it] > tin[curNode]) {
                bridges.push_back({it, curNode});
            }
        }
        else {
            lowT[curNode] = min(lowT[curNode], lowT[it]);
        }
    }
}


vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e) {
    // Write your code here
    vector<int> adj[v];
    for(auto it : edges) {
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }

    int timer = 0;
    vector<int> vis(v, 0);
    int timeIns[v];
    int lowTime[v];
    int node = 0, parent = -1;
    vector<vector<int>> bridges;
    dfs(node, parent, vis, adj, timer, timeIns, lowTime, bridges);

    return bridges;
}

*/



#include <bits/stdc++.h>
using namespace std;


class Solution {

private:
    void dfs(int curNode, int parent, vector<int>& vis, vector<int> adj[], int &timer, int timeIns[], int lowTime[], vector<vector<int>> &bridges) {
        vis[curNode] = 1;
        timeIns[curNode] = lowTime[curNode] = timer++;

        for(auto it : adj[curNode]) {
            if(it == parent) continue;

            if(!vis[it]) {
                dfs(it, curNode, vis, adj, timer, timeIns, lowTime, bridges);
                lowTime[curNode] = min(lowTime[curNode], lowTime[it]);
                // check if this current-node is bridge
                if(lowTime[it] > timeIns[curNode]) {
                    bridges.push_back({it, curNode});
                }
            }
            else {
                lowTime[curNode] = min(lowTime[curNode], lowTime[it]);
            }
        }
    }


public:

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> adj[n];
        for(auto it : connections) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<int> vis(n, 0);
        int timer = 0;
        int timeInsertion[n];
        int lowTime[n];
        int node = 0, parent = -1;

        vector<vector<int>> bridges;
        dfs(node, parent, vis, adj, timer, timeInsertion, lowTime, bridges);

        return bridges;
    }

};



int main() {

    int n = 4;
    vector<vector<int>> connections = {
        {0, 1}, {1, 2},
        {2, 0}, {1, 3}
    };

    Solution obj;
    vector<vector<int>> bridges = obj.criticalConnections(n, connections);
    cout << "The Bridges in Graph is: ";
    for (auto it : bridges) {
        cout << "[" << it[0] << ", " << it[1] << "] ";
    }
    cout << endl;
    return 0;
}
