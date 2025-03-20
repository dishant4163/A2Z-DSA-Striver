// Detect Cycle in an Undirected Graph (using BFS)


/* // Link-> 
//  https://www.naukri.com/code360/problems/cycle-detection-in-undirected-graph_1062670  




*/


#include<iostream>
#include<vector>
#include<queue>
using namespace std;

bool bfsDetectCyle(int src, int vis[], vector<int> adjList[]) {
    vis[src] = 1;
    queue<pair<int, int>> q;
    q.push({src, -1});

    while(!q.empty()) {
        int node = q.front().first;
        int parent  = q.front().second;
        q.pop();

        for(auto adjNode : adjList[node]) {
            if(!vis[adjNode]) {
                vis[adjNode] = 1;
                q.push({adjNode, node});
            }
            else if(parent != adjNode) return true;
        }
    }

    return false;
}


bool isCycle(int V, vector<int> adjList[]){
    int vis[V] = {0};

    //check for multiple connected components graph
    for(int i=0; i < V; i++) {
        if(!vis[i]) {
            if( bfsDetectCyle(i, vis, adjList) == true)
                return true;
        }
    }

    return false;
}


int main() {

    int V = 5; // Number of vertices
    vector<int> adjList[V]; // Adjacency list representation

    // Adding edges
    adjList[0].push_back(1);
    adjList[1].push_back(2);
    adjList[2].push_back(0);
    adjList[2].push_back(3);

    if (isCycle(V, adjList)) {
        cout << "Graph contains a cycle" << endl;
    } else {
        cout << "Graph does not contain a cycle" << endl;
    }


    return 0;
}