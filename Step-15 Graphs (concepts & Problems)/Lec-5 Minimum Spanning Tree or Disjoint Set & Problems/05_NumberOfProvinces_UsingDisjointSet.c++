// Number of Provinces using Disjoint Set


/* // Problem-Link-> https://www.naukri.com/code360/problems/find-the-number-of-states_1377943  


// Solve using Disjoint Set
class DisjointSet {
    
public:
    vector<int> rank, size, parent;
    DisjointSet(int n) {
        parent.resize(n+1);
        size.resize(n+1, 1);
        rank.resize(n+1, 0);

        for(int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findUPar(int node) {
        if(node == parent[node]) return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if(ulp_u == ulp_v) return;
        if(rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++; 
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if(ulp_u == ulp_v) return;
        if(size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }

};





int findNumOfProvinces(vector<vector<int>> &roads, int n) {
    // Write your code here.
    DisjointSet ds(n);
    for(int i=0; i < n; i++) {
        for(int j=0; j < n; j++) {
            if(roads[i][j]) {
                ds.unionBySize(i+1, j+1);
            }
        }
    }

    int cnt = 0;
    for(int i = 1; i <= n; i++) {
        if(ds.parent[i] ==  i) cnt++;
    }

    return cnt;
} 

*/



#include<bits/stdc++.h>
using namespace std;


// Solve using Disjoint Set
class DisjointSet {
    
public:
    vector<int> rank, size, parent;
    DisjointSet(int n) {
        parent.resize(n+1);
        size.resize(n+1, 1);
        rank.resize(n+1, 0);

        for(int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findUPar(int node) {
        if(node == parent[node]) return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if(ulp_u == ulp_v) return;
        if(rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++; 
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);

        if(ulp_u == ulp_v) return;
        if(size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }

};



int numProvinces(vector<vector<int>> adj, int V) {
    DisjointSet solve(V);
    for(int i=0; i < V; i++) {
        for(int j=0; j < V; j++) {
            if(adj[i][j] == 1) {
                solve.unionBySize(i, j);
            }
        }
    }

    int cnt = 0;
    for(int i = 0; i < V; i++) {
        if(solve.findUPar(i) == i) cnt++;
    }

    return cnt;
}


int main() {

    vector<vector<int>> adj =
    {
        {1, 0, 1},
        {0, 1, 0},
        {1, 0, 1}
    };

    int V = 3;

    cout << "Number of Provinces is: " << numProvinces(adj, V) << endl;



    return 0;
}

