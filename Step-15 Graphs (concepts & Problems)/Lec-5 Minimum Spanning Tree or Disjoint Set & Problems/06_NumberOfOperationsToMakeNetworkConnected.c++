// Number of Operations to Make Network Connected


/*// Problem-Link-> https://www.naukri.com/code360/problems/number-of-operations-to-make-graph-connected_1385179      


class DisjointSet {
public:
    vector<int> rank, parent, size;
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
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
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};




int makeGraphConnected(int n, vector < pair < int,int > > edges, int m) {
    // Write Your Code here
	DisjointSet ds(n+1);
    int cntExtras = 0;
    for(auto it : edges) {
        int u = it.first;
        int v = it.second;

        if(ds.findUPar(u) == ds.findUPar(v)) {
            cntExtras++;
        }
        else {
            ds.unionBySize(u, v);
        }
    }

    int cntC = 0; // count component
    for(int i = 1; i <= n; i++) {
        if(ds.parent[i] == i) cntC++;
    }

    int ans = cntC - 1; // no. of edges required
    if(cntExtras >= ans) return ans;
    return -1;
}

*/



#include<bits/stdc++.h>
using namespace std;



class DisjointSet {
public:
    vector<int> rank, parent, size;
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
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
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};




int Solve(int n, vector<vector<int>>& edge) {
    DisjointSet ds(n);
    int cntExtras = 0;
    for(auto it : edge) {
        int u = it[0];
        int v = it[1];

        if(ds.findUPar(u) == ds.findUPar(v)) {
            cntExtras++;
        }
        else {
            ds.unionBySize(u, v);
        }
    }

    int cntC = 0; // count component
    for(int i = 0; i<n; i++) {
        if(ds.parent[i] == i) cntC++;
    }

    int ans = cntC - 1; // no. of edges required
    if(cntExtras >= ans) return ans;
    return -1;
}



int main() {

    int V = 9;
    vector<vector<int>> edge = {{0, 1}, {0, 2}, {0, 3}, {1, 2}, {2, 3}, {4, 5}, {5, 6}, {7, 8}};

    int ans = Solve(V, edge);
    cout << "The number of operations needed: " << ans << endl;


    return 0;
}
