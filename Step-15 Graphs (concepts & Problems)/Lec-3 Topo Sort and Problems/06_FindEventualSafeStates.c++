// Find Eventual Safe States - BFS - Topological Sort

/* // Problem-Link-> https://www.naukri.com/code360/problems/safe-nodes-in-the-graph_1376703
// Solve using BFS

#include <bits/stdc++.h> 
vector<int> safeNodes(vector<vector<int>> &edges, int n, int e) {
    // Write your code here.
    vector<int> adjReverse[n];
    int indegree[n] = {0};
    for(int i = 0; i < edges.size(); i++) {
        adjReverse[edges[i][1]].push_back(edges[i][0]);
        indegree[edges[i][0]]++;
    }

    queue<int> q;
    for(int i = 0; i < n; i++) {
        if(indegree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> safeNode;
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        safeNode.push_back(node);

        for(auto it : adjReverse[node]) {
            indegree[it]--;
            if(indegree[it] == 0) q.push(it);
        }
    }

    sort(safeNode.begin(), safeNode.end());
    return safeNode;
}

*/



#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        vector<int> adjReverse[V];
        int indegree[V] = {0};
        for(int i=0; i < V; i++) {
            // usaully we go from "i -> it" & for
            // reverse adj we go "it -> i"
            for(auto it : adj[i]) {
                adjReverse[it].push_back(i);
                indegree[i]++;
            }
        }

        queue<int> q;
        vector<int> safeNodes;
        for(int i=0; i < V; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }

        while(!q.empty()) {
            int node = q.front();
            q.pop();
            safeNodes.push_back(node);

            for(auto it : adjReverse[node]) {
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }

        sort(safeNodes.begin(), safeNodes.end());

        return safeNodes;
    }
};





int main() {

    vector<int> adj[12] = {{1}, {2}, {3, 4}, {4, 5}, {6}, {6}, {7}, {}, {1, 9}, {10},
		{8}, {9}
	};
	int V = 12;

    Solution soln;

	vector<int> safeNodes = soln.eventualSafeNodes(V, adj);
    cout << "Eventual Safe States are: ";
	for (auto node : safeNodes) {
		cout << node << " ";
	}
	cout << endl;


    return 0;
}
