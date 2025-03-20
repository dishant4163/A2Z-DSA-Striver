// Course Schedule-i


/* // Problem-Link->  https://www.naukri.com/code360/problems/course-schedule_985288  


#include <bits/stdc++.h> 
string canFinish(vector<vector<int>>& prerequisites, int n, int m) {
    // Write your code here
    // Return "Yes" if possible, Else return "No"

    vector<int> adj[n + 1]; // 1st form graph & indexing is 1-based
    for(auto it : prerequisites) {
        adj[it[1]].push_back(it[0]);
    }

    int indegree[n + 1] = {0};
    for(int i = 1; i < n+1; i++) {
        for(auto it : adj[i]) {
            indegree[it]++;
        }
    }

    queue<int> q;
    for(int i=1; i < n+1; i++) {
        if(indegree[i] == 0) q.push(i);
    }

    vector<int> topo;
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        topo.push_back(node);

        for(auto it : adj[node]) {
            indegree[it]--;
            if(indegree[it] == 0) q.push(it);
        }
    }

    if(topo.size() == n) return "Yes";
    return "No";
}

*/



#include<iostream>
#include<vector>
#include<queue>
using namespace std;

/* //Complexity Analysis
 Time Complexity: O(V+E), where V = no. of nodes and E = no. of edges. This is a simple BFS algorithm.

 Space Complexity: O(N) + O(N) ~ O(2N), O(N) for the indegree array, and O(N) for the 
queue data structure used in BFS(where N = no.of nodes). Extra O(N) for storing the topological sorting. Total ~ O(3N).
*/


bool isPossible(int V, vector<pair<int, int> >& prerequisites) {
    // 1st formed graph & its Zero-based indexing
    vector<int> adj[V];
    for(auto it : prerequisites) {
        adj[it.first].push_back(it.second);
    }

    int indegree[V] = {0};
    for(int i=0; i < V; i++) {
        for(auto it: adj[i]) {
            indegree[it]++;
        }
    }

    queue<int> q;
    for(int i=0; i < V; i++) {
        if(indegree[i] == 0) q.push(i);
    }

    vector<int> topo;
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        topo.push_back(node);

        for(auto it : adj[node]) {
            indegree[it]--;
            if(indegree[it] == 0) q.push(it);
        }
    }

    if(topo.size() == V) return true;

    return false;
}



int main() {

    vector<pair<int, int>> prerequisites;
	int n = 4;
	prerequisites.push_back({1, 0});
	prerequisites.push_back({2, 1});
	prerequisites.push_back({3, 2});

	bool ans = isPossible(n, prerequisites);

	if (ans) cout << "YES";
	else cout << "NO";
	cout << endl;




    return 0;
}
