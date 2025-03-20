// Detect Cycle in an Undirected Graph (using DFS)


/* // Link-> 



*/


#include<iostream>
#include<vector>
using namespace std;


bool dfsDetectCycle(int node, int parent, int vis[], vector<int> adjList[]) {
    vis[node] = 1;

    for(auto adjNode : adjList[node]) {
        if(!vis[adjNode]) {
            if (dfsDetectCycle(adjNode, node, vis, adjList) == true)
                return true;

            else if (parent != adjNode) return true;
        }
    }

    return false;
}

bool isCycle(int V, vector<int> adjList[]) {
    int vis[V] = {0};

    for(int i=0; i < V; i++) {
        if(!vis[i]) {
            if (dfsDetectCycle(i, -1, vis, adjList) == true)
                return true;
        }
    }

    return false;
}


int main() {

    int V = 5; // Number of vertices
    vector<int> adjList[V]; // Adjacency list representation

    // Adding edges (example)
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