// Most Stones Removed with Same Row or Column


/* // Problem-Link-> https://www.naukri.com/code360/problems/most-stones-removed-with-same-row-or-column_1376597   

#include <bits/stdc++.h>

class DisjointSet {
    vector<int> rank, parent, size;
public:
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



int removeStones(vector<vector<int>> &stones){
	// Write your code here.
	int n = stones.size(); // no. of stones 

	//since no actual size is clearly mentioned
	int maxRow = 0, maxCol = 0;
	for(auto it : stones) {
		maxRow = max(maxRow, it[0]);
		maxCol = max(maxCol, it[1]);
	}

	DisjointSet ds(maxRow + maxCol + 1);
	unordered_map<int, int> stoneNodes;
	for(auto it : stones) {
		int nodeRow = it[0];
		// for node-Col we have to co-ordinates mapping so that
		// they did'nt overlaps with the node-Row
		int nodeCol = it[1] + maxRow + 1;

		ds.unionBySize(nodeRow, nodeCol);
		stoneNodes[nodeRow] = 1;
		stoneNodes[nodeCol] = 1;
	}

	int cnt = 0;
	for(auto it : stoneNodes) {
		if(ds.findUPar(it.first) == it.first) cnt++;
	}

	return n - cnt;
}


*/



#include <bits/stdc++.h>
using namespace std;


class DisjointSet {

    vector<int> rank, parent, size;

public:

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



int maxRemove(vector<vector<int>>& stones, int n) {
    // Since there is no actual size is not mentioned so we track the last stone 
    // int row & in the col
    int maxRow = 0;
    int maxCol = 0;
    for(auto it : stones) {
        maxRow = max(maxRow, it[0]);
        maxCol = max(maxCol, it[1]);
    }

    DisjointSet ds(maxRow + maxCol + 1);  // declare DS size & +1 for safety
    unordered_map<int, int> stoneNodes;
    for(auto it : stones) {
        int nodeRow = it[0];
        // for node col we have to do co-ordinate mapping i.e, co-ordinate shift 
        int nodeCol = it[1] + maxRow + 1;

        ds.unionBySize(nodeRow, nodeCol);
        stoneNodes[nodeRow] = 1;
        stoneNodes[nodeCol] = 1;
    }

    int cnt = 0;
    for(auto it : stoneNodes) {
        if(ds.findUPar(it.first) == it.first) cnt++;
    }

    return n - cnt; // no. of stones - no. of unique valid ultimate parent
}



int main() {

    int n = 6;
    vector<vector<int>> stones = {
        {0, 0}, {0, 2},
        {1, 3}, {3, 1},
        {3, 2}, {4, 3}
    };

    int ans = maxRemove(stones, n);
    cout << "The maximum number of stones we can remove is: " << ans << endl;


    return 0;
}
