// Making A Large Island - DSU


/* // Problem-Link-> https://www.naukri.com/code360/problems/making-the-largest-island_1381282


#include<bits/stdc++.h>

class DisjointSet{

public:
    vector<int> rank, size, parent;
    DisjointSet(int n) {
        rank.resize(n+1, 0);
        size.resize(n+1);
        parent.resize(n+1);
        for(int i=0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if(parent[node] == node) return node;

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


bool isValid(int newr, int newc, int n) {
    return newr >= 0 && newr < n && newc >= 0 && newc < n;
}


int maximumIslandSize(vector<vector<int>> &grid){
	// Write your code here
	int n = grid.size();
	DisjointSet ds(n*n);
	for(int r = 0; r < n; r++) {
		for(int c = 0; c < n; c++) {
			if(grid[r][c] == 0) continue;
			int dr[] = {-1,0,1,0};
			int dc[] = {0,1,0,-1};
			for(int i=0; i < 4; i++) {
				int nr = r + dr[i];
				int nc = c + dc[i];
				if(isValid(nr, nc, n) && grid[nr][nc] == 1) {
					int nodeNO = r * n + c;
					int adjNodeNO = nr * n + nc;
					ds.unionBySize(nodeNO, adjNodeNO);
				}
			}
		}
	}

    int mx = 0;
	for(int r = 0; r < n; r++) {
		for(int c = 0; c < n; c++) {
			if(grid[r][c] == 1) continue;
			int dr[] = {-1,0,1,0};
			int dc[] = {0,1,0,-1};
			set<int> compo;

			for(int i=0; i < 4; i++) {
				int nr = r + dr[i];
				int nc = c + dc[i];
				if(isValid(nr, nc, n)) {
					if(grid[nr][nc] == 1) {
						compo.insert(ds.findUPar(nr * n + nc));
					}
				}
			}

			int totalSize = 0;
			for(auto it : compo) {
				totalSize += ds.size[it];
			}

			mx = max(mx, totalSize + 1);
		}

		for(int cellNo = 0; cellNo < n*n; cellNo++) {
			mx = max(mx, ds.size[ds.findUPar(cellNo)]);
		}
	}

	return mx;
}



*/


#include<bits/stdc++.h>
using namespace std;



class DisjointSet{

public:
    vector<int> rank, size, parent;
    DisjointSet(int n) {
        rank.resize(n+1, 0);
        size.resize(n+1);
        parent.resize(n+1);
        for(int i=0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if(parent[node] == node) return node;

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




class Solution {
private: 

    bool isValid(int newr, int newc, int n) {
        return newr >= 0 && newr < n && newc >= 0 && newc < n;
    }

public:

    int MaxConnection(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n * n);

        // Step-1 Connecting the Components
        for(int row = 0; row < n; row++) {
            for(int col = 0; col < n; col++) {
                if(grid[row][col] == 0) continue;
                int dr[] = {-1,0,1,0};
                int dc[] = {0,1,0,-1};
                for(int i=0; i < 4; i++) {
                    int newr = row + dr[i];
                    int newc = col + dc[i];
                    if(isValid(newr, newc, n) && grid[newr][newc] == 1) {
                        int nodeNo = row * n + col; // getting Cell no
                        int adjNodeNo = newr * n + newc; // getting adjacent cell no
                        ds.unionBySize(nodeNo, adjNodeNo);
                    }
                }
            }
        }

        //Step-2 try to convert 0 to 1, only valid one which gives genuine Ans
        int maxLand = 0;
        for(int row = 0; row < n; row++) {
            for(int col = 0; col < n; col++) {
                if(grid[row][col] == 1) continue;
                int dr[] = {-1,0,1,0};
                int dc[] = {0,1,0,-1};

                set<int> components;

                for(int i=0; i < 4; i++) {
                    int newr = row + dr[i];
                    int newc = col + dc[i];
                    if(isValid(newr, newc, n)) {
                        if(grid[newr][newc] == 1) {
                            components.insert(ds.findUPar(newr * n + newc));
                        }
                    }
                }

                // figure out size of this Component
                int totalSize = 0;
                for(auto it : components) {
                    totalSize += ds.size[it];
                }

                maxLand = max(maxLand, totalSize + 1); // + 1, bcz the convert 0 to 1 is to be add in size

            }
        }

        // If entire cells having all 1 then its ultimate parent size
        for(int cellNo = 0; cellNo < n * n; cellNo++) {
            maxLand = max(maxLand, ds.size[ds.findUPar(cellNo)]);
        }

        return maxLand;
    }

};



int main() {

    vector<vector<int>> grid = {
        {1, 1, 0, 1, 1, 0}, {1, 1, 0, 1, 1, 0},
        {1, 1, 0, 1, 1, 0}, {0, 0, 1, 0, 0, 0},
        {0, 0, 1, 1, 1, 0}, {0, 0, 1, 1, 1, 0}
    };

    Solution sol;

    int ans = sol.MaxConnection(grid);
    cout << "The largest group of connected 1s is of size: " << ans << endl;



    return 0;
}

