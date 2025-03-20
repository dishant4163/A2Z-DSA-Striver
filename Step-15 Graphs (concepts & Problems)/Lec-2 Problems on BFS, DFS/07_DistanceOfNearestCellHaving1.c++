// Distance of Cell Having 1 OR 0/1 Matrix


/* // Link-> https://www.naukri.com/code360/problems/distance-of-nearest-cell-having-1-in-a-binary-matrix_1169913

#include<queue>

vector<vector<int>> nearest(vector<vector<int>>& mat, int n, int m) {
    // Write your code here.
    vector<vector<int>> vis(n, vector<int>(m,0));
    vector<vector<int>> dist(n, vector<int>(m,0));
    queue<pair<pair<int, int>, int>> q;

    for(int i=0; i < n; i++) {
        for(int j=0; j < m; j++) {
            if(mat[i][j] == 1) {
                q.push({{i, j}, 0}); //row, col, steps/distance
                vis[i][j] = 1;
            }
            else {
                vis[i][j] = 0;
            }
        }
    }

    int delR[] = {-1,0,1,0};
    int delC[] = {0,1,0,-1};

    while(!q.empty()) {
        int row = q.front().first.first;
        int col = q.front().first.second;
        int steps = q.front().second;
        q.pop();

        dist[row][col] = steps;

        for(int i=0; i < 4; i++) {
            int nr = row + delR[i];
            int nc = col + delC[i];

            if(nr >= 0 && nr < n && nc >= 0 && nc < m && vis[nr][nc] == 0) {
                vis[nr][nc] = 1;
                q.push({{nr, nc}, steps+1 });
            }
        }
    }

    return dist;
}


*/



#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<vector<int>> nearest(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));
    vector<vector<int>> dist(n, vector<int>(m, 0));
    queue<pair<pair<int, int>, int>> q;

    for(int i = 0; i < n; i++) {
        for(int j=0; j < m; j++) {
            if(grid[i][j] == 1) {
                q.push({{i,j}, 0});
                vis[i][j] = 1;
            }
            else {
                vis[i][j] = 0;
            }
        }
    }

    int deltaR[] = {-1, 0, +1, 0};
    int deltaC[] = {0, +1, 0, -1};

    while(!q.empty()) {
        int row = q.front().first.first;
        int col = q.front().first.second;
        int steps = q.front().second;
        q.pop();

        dist[row][col] = steps;

        for(int i=0; i < 4; i++) {
            int nR = row + deltaR[i];
            int nC = col + deltaC[i];

            if(nR >= 0 && nR < n && nC >= 0 && nC < m && vis[nR][nC] == 0) {
                vis[nR][nC] = 1;
                q.push({{nR, nC}, steps+1});
            }
        }
    }

    return dist;
}


int main() {

    vector<vector<int>>grid{
        {0,1,1,0},
        {1,1,0,0},
        {0,0,1,1}
    };

	vector<vector<int>> ans = nearest(grid);

	for(auto i: ans){
		for(auto j: i)
			cout << j << " ";
		cout << "\n";
	}



    return 0;
}
