// Count Number Of Distinct Islands using DFS




#include<bits/stdc++.h>
using namespace std;

void dfs(int row, int col, vector<vector<int>>& vis, vector<vector<int>>& grid, vector<pair<int, int>>& vecList, int baseRow, int baseCol) {
    int n = grid.size(), m = grid[0].size();
    vis[row][col] = 1;
    vecList.push_back({row - baseRow, col - baseCol});

    int deltaRow[] = {-1, 0, 1, 0};
    int deltaCol[] = {0, -1, 0, 1};

    for(int i = 0; i < 4; i++) {
        int nrow = row + deltaRow[i];
        int ncol = col + deltaCol[i];

        if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m 
        && !vis[nrow][ncol] && grid[nrow][ncol] == 1) {
            dfs(nrow, ncol, vis, grid, vecList, baseRow, baseCol);
        }
    }
}


int countDistinctIslands(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));
    set<vector<pair<int, int>>> st;
    for(int r=0; r < n; r++) {
        for(int c=0; c < m; c++) {
            if(!vis[r][c] && grid[r][c] == 1) {
                // declaring vectorList to store ans
                vector<pair<int, int>> vecList;
                dfs(r, c, vis, grid, vecList, r, c);
                st.insert(vecList);
            }
        }
    }

    return st.size();
}



int main() {

    vector<vector<int>> grid {
        {1, 1, 0, 1, 1},
        {1, 0, 0, 0, 0},
        {0, 0, 0, 0, 1},
        {1, 1, 0, 1, 1}
    };

    cout << "The number of distinct Islands is: " << countDistinctIslands(grid) << endl;


    return 0;
}

