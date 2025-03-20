// Number of Islands-2


/* // Problem-Link-> https://www.naukri.com/code360/problems/number-of-islands-ii_1266048

#include<bits/stdc++.h>

class DisjointSet{
    vector<int> rank, size, parent; // declared as private
public:

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


vector<int> numOfIslandsII(int n, int m, vector<vector<int>> &q){
	// Write your code here.
	DisjointSet ds(n*m);
	int cnt = 0;
	vector<int> ans;
	int vis[n][m];
	memset(vis, 0, sizeof vis);

	for(auto it : q) {
		int r = it[0];
		int c = it[1];

		if(vis[r][c] == 1) {
			ans.push_back(cnt);
			continue;
		}

		vis[r][c] = 1;
		cnt++;

		int dr[] = {-1, 0, 1, 0};
		int dc[] = {0, 1, 0, -1};

		for(int i=0; i < 4; i++) {
			int adjr = r + dr[i];
			int adjc = c + dc[i];

			if(adjr >=0 && adjr < n && adjc >= 0 && adjc < m && vis[adjr][adjc] == 1) {
				int nodeNO = r * m + c;
				int adjNodeNO = adjr * m + adjc;

				if(ds.findUPar(nodeNO) != ds.findUPar(adjNodeNO)) {
					cnt--;
					ds.unionBySize(nodeNO, adjNodeNO);
				}
			}
		}

		ans.push_back(cnt);
    }

	return ans;
}


*/


#include<bits/stdc++.h>
using namespace std;



class DisjointSet{
    vector<int> rank, size, parent; // declared as private
public:

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



vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
    DisjointSet ds(n * m);
    int cnt = 0;
    int vis[n][m];
    memset(vis, 0, sizeof vis);
    vector<int> ans;

    for(auto it : operators) {
        int row = it[0];
        int col = it[1];

        if(vis[row][col] == 1) {
            ans.push_back(cnt);
            continue;
        }

        vis[row][col] = 1;
        cnt++;

        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};

        for(int i=0; i < 4; i++) {
            int adjr = row + dr[i];
            int adjc = col + dc[i];

            if(adjr >= 0 && adjr < n && adjc >= 0 && adjc < m 
            && vis[adjr][adjc] == 1) {
                int nodeNum = row * m + col;
                int adjNodeNum = adjr * m + adjc;

                if(ds.findUPar(nodeNum) != ds.findUPar(adjNodeNum)) {
                    cnt--;
                    ds.unionBySize(nodeNum, adjNodeNum);
                }
            }
        }

        ans.push_back(cnt);
    }

    return ans;
}


int main() {

    int n = 4, m = 5;
    vector<vector<int>> operators = {{0, 0}, {0, 0}, {1, 1}, {1, 0}, {0, 1},
        {0, 3}, {1, 3}, {0, 4}, {3, 2}, {2, 2}, {1, 2}, {0, 2}
    };

    vector<int> ans = numOfIslands(n, m, operators);
    cout << "The online queries ansList is : ";
    for (auto res : ans) {
        cout << res << " ";
    }



    return 0;
}
