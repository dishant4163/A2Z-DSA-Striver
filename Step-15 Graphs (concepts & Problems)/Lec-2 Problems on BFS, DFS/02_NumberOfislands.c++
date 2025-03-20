// Number of Islands (Using BFS)


/*// Link->  https://www.naukri.com/code360/problems/find-number-of-islands_630512


#include<bits/stdc++.h>

void bfs(int row, int col, vector<vector<int>>& vis, int**arr, int n, int m) {
   vis[row][col] = 1;
   queue<pair<int, int>> q;
   q.push({row, col});

   int deltaR[4] = {-1, 0, 1, 0};
   int deltaC[4] = {0, 1, 0, -1};

   while(!q.empty() ) {
      int row = q.front().first; 
      int col = q.front().second;
      q.pop();

      for(int i = 0; i < 4; i++) {
         for(int j = 0; j < 4; j++) {
            int newR = row + deltaR[i];
            int newC = col + deltaC[j];

            if (newR >= 0 && newR < n && newC >= 0 && newC < m 
            && arr[newR][newC] == 1 && !vis[newR][newC]) {
               vis[newR][newC] = 1;
               q.push({newR, newC});
            }
         }
      }
   }
}


int getTotalIslands(int** arr, int n, int m) {
   // Write your code here.
   int cnt = 0;
   vector<vector<int>> vis(n, vector<int>(m,0));

   for(int i = 0; i < n; i++) {
      for(int j=0; j < m; j++) {
         if(!vis[i][j] && arr[i][j] == 1) {
            cnt++;
            bfs(i,j,vis, arr, n, m);
         }
      }
   }

   return cnt;
}



*/



#include<iostream>
#include<vector>
#include<queue>
using namespace std;


void bfsHelper(int r, int c, vector<vector<int>>& vis, vector<vector<char>>& grid) {
    vis[r][c] = 1;
    queue<pair<int, int>> q;
    q.push({r, c});
    int n = grid.size(), m = grid[0].size();

    while(!q.empty()) {
        int row = q.front().first, col = q.front().second;
        q.pop();

        // Traverse in the Neighbours & mark them it as Land
        for(int deltaRow = -1; deltaRow <= 1; deltaRow++) {
            for(int deltaCol = -1; deltaCol <= 1; deltaCol++) {
                int newRow = row + deltaRow;
                int newCol = col + deltaCol;

                // neighbour row and column is valid, and is an unvisited land
                if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < m 
                && grid[newRow][newCol] == '1' && !vis[newRow][newCol]) {
                    vis[newRow][newCol] = 1;
                    q.push({newRow, newCol});
                }
            }
        }
    }
}

int numIslands(vector<vector<char>>& grid) {
    int n = grid.size(), m = grid[0].size(), cntIslands = 0;
    vector<vector<int>> vis(n, vector<int>(m, 0));

    for(int row = 0; row < n; row++) {
        for(int col = 0; col < m; col++) {
            // check is should not be visited & it must be land
            if(!vis[row][col] && grid[row][col] == '1') {
                cntIslands++;
                bfsHelper(row, col, vis, grid);
            }
        }
    }

    return cntIslands;
}


int main() {

    // n: row, m: column
    vector<vector<char>> grid
    {
        {'0', '1', '1', '1', '0', '0', '0'},
        {'0', '0', '1', '1', '0', '1', '0'}
    };

    cout << "Number of Islands is: " << numIslands(grid) << endl;



    return 0;
}
