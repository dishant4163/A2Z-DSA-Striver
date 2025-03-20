// Number of Enclaves (flood fill implementation - Multi-source BFS)




#include<iostream>
#include<vector>
#include<queue>
using namespace std;


int numberOfEnclaves(vector<vector<int>> &grid) {
    int n = grid.size(), m = grid[0].size();
    int vis[n][m] = {0};
    queue<pair<int, int>> q;
    q.pop();

    for(int i=0; i < n; i++) {
        for(int j=0; j < m; j++) {
            if(i == 0 || i == n-1 || j == 0 || j == m-1) {
                if(grid[i][j] == 1) {
                    q.push({i, j});
                    vis[i][j] = 1;
                }
            }
        }
    }

    int deltaR[] = {-1,0,1,0};
    int deltaC[] = {0,1,0,-1};

    while(!q.empty()) {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        for(int i=0; i < 4; i++) {
            int nr = row + deltaR[i];
            int nc = col + deltaC[i];

            if(nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 1 && vis[nr][nc] == 0) {
                q.push({nr, nc});
                vis[nr][nc] = 1;
            }
        }
    }

    int count = 0;
    for(int i=0; i < n; i++) {
        for(int j=0; j < m; j++) {
            if (grid[i][j] == 1 & vis[i][j] == 0)
                count++;
        }
    }

    return count;
}


int main() {

    vector<vector<int>> grid{
        {0, 0, 0, 0},
        {1, 0, 1, 0},
        {0, 1, 1, 0},
        {0, 0, 0, 0}};
        

    cout << "The output is: " << numberOfEnclaves(grid) << endl;


    return 0;
}
