// Course Schedule-ii


/*// Problem-Link-> https://www.naukri.com/code360/problems/course-schedule-ii_1069243 


vector<int> findSchedule(int numCourses, vector<pair<int, int>> &prerequisites) {
    // 1st formed graph & its 1-based indexing
    vector<int> adj[numCourses + 1];
    for(auto it : prerequisites) {
        adj[it.first].push_back(it.second);
    }

    int indegree[numCourses+1] = {0};
    for(int i=1; i < numCourses+1; i++) {
        for(auto it: adj[i]) {
            indegree[it]++;
        }
    }

    queue<int> q;
    for(int i=0; i < numCourses; i++) {
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

    if(topo.size() == numCourses) return topo;
    return {};
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


vector<int> findOrder(int n, int m, vector<vector<int>> prerequisites) {
    vector<int> adj[n];
    for(auto it : prerequisites) {
        adj[it[1]].push_back(it[0]);
    }

    int indegree[n] = {0};
    for(int i=0; i < n; i++) {
        for(auto it : adj[i]) {
            indegree[it]++;
        }
    }

    queue<int> q;
    for(int i=0; i < n; i++) {
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

    if(topo.size() == n) return topo;
    return {};
}


int main() {

	int N = 4, M = 3;

	vector<vector<int>> prerequisites(3);
	prerequisites[0].push_back(0);
	prerequisites[0].push_back(1);

	prerequisites[1].push_back(1);
	prerequisites[1].push_back(2);

	prerequisites[2].push_back(2);
	prerequisites[2].push_back(3);

	vector<int> ans = findOrder(N, M, prerequisites);

	for (auto task : ans) {
		cout << task << " ";
	}
	cout << endl;


	return 0;
}
