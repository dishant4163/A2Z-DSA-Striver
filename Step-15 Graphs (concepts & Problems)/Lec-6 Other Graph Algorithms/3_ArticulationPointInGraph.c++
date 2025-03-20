// Articulation Point in Graph



#include <bits/stdc++.h>
using namespace std;


class Solution {
private:

    void dfs(int node, int parent, vector<int>& vis, vector<int> adj[], int tin[], int lowT[], vector<int>& mark, int timer) {
        vis[node] = 1;
        tin[node] = lowT[node] = timer++;
        int child = 0;
        for(auto it : adj[node]) {
            if(it == parent) continue;

            if(!vis[it]) {
                dfs(it, node, vis, adj, tin, lowT, mark, timer);
                lowT[node] = min(lowT[node], lowT[it]);
                // check for the articulation node
                if(lowT[it] >= tin[node] && parent != -1) {
                    mark[node] = 1;
                }
                child++;
            }
            else {
                lowT[node] = min(lowT[node], lowT[it]);
            }
        }

        // if node is the starting node & have parent -1
        if(child > 1 && parent == -1) {
            mark[node] = 1;
        }
    }

public:
    vector<int> articulationPoints(int n, vector<int>adj[]) {
        vector<int> vis(n, 0);
        int tin[n];
        int lowT[n];
        int timer = 0;
        int parent = -1;
        vector<int> mark(n, 0);

        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                dfs(i, parent, vis, adj, tin, lowT, mark, timer);
            }
        }

        vector<int> ans;
        for(int i=0; i < n; i++) {
            if(mark[i] == 1) {
                ans.push_back(i);
            }
        }
        if(ans.size() == 0) return {-1};
        return ans;
    }
};




int main() {

    int n = 5;
    vector<vector<int>> edges = {
        {0, 1}, {1, 4},
        {2, 4}, {2, 3}, {3, 4}
    };

    vector<int> adj[n];
    for (auto it : edges) {
        int u = it[0], v = it[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    Solution obj;
    vector<int> nodes = obj.articulationPoints(n, adj);
    cout << "The output is: ";
    for (auto node : nodes) {
        cout << node << " ";
    }
    cout << endl;


    return 0;
}
