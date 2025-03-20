// Surrounded Regions OR Replace O's with X's


/* // Link-> https://www.naukri.com/code360/problems/replace-o-with-x_630517


#include<vector>

void dfs(int row, int col, vector<vector<int>>& vis, char **arr, int n, int m) {
    vis[row][col] = 1;
    int deltaR[] = {-1,0,1,0};
    int deltaC[] = {0,1,0,-1};

    for(int i=0; i < 4; i++) {
        int nr = row + deltaR[i];
        int nc = col + deltaC[i];

        if(nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc] && arr[nr][nc] == 'O') {
            dfs(nr, nc, vis, arr, n, m);
        }
    }
}

void replaceOWithX(char** arr, int n, int  m) {
    //Write your code here
    vector<vector<int>> vis(n, vector<int>(m, 0));

    // traverse through first row & last row
    for(int j = 0; j < m; j++) {
        // first row
        if(!vis[0][j] && arr[0][j] == 'O') {
            dfs(0, j, vis, arr, n, m);
        }
        // last row
        if(!vis[n-1][j] && arr[n-1][j] == 'O') {
            dfs(n-1, j, vis, arr, n, m);
        }
    }

    // traverse through first col & last col
    for(int i = 0; i < n; i++) {
        // first col
        if(!vis[i][0] && arr[i][0] == 'O') {
            dfs(i, 0, vis, arr, n, m);
        }
        // last col
        if(!vis[i][m-1] && arr[i][m-1] == 'O') {
            dfs(i, m-1, vis, arr, n, m);
        }
    }

    // if unvisited O then convert to X 
    for(int i=0; i < n; i++) {
        for(int j=0; j < m; j++) {
            if(!vis[i][j] && arr[i][j] == 'O')
                arr[i][j] = 'X';
        }
    }

}

*/



#include<iostream>
#include<vector>

using namespace std;

void dfs(int row, int col, vector<vector<int>>& vis, 
vector<vector<char>>& mat, int delR[], int delC[]) {
    int n = mat.size(), m = mat[0].size();
    vis[row][col] = 1;

    // check for top, right, bottom, left 
    for(int i=0; i < 4; i++) {
        int nr = row + delR[i];
        int nc = col + delC[i];

        if(nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc] && mat[nr][nc] == 'O') {
            dfs(nr, nc, vis, mat, delR, delC);
        }
    }
}

vector<vector<char>> fill(int n, int m, vector<vector<char>> mat) {
    int deltaR[] = {-1, 0, 1, 0};
    int deltaC[] = {0, 1, 0, -1};
    vector<vector<int>> vis(n, vector<int>(m,0));

    // traverse first row and last row
    for(int j = 0; j < m; j++) {
        // first row
        if(!vis[0][j] && mat[0][j] == 'O') {
            dfs(0, j, vis, mat, deltaR, deltaC);
        }
        // last row
        if(!vis[n-1][j] && mat[n-1][j] == 'O') {
            dfs(n-1, j, vis, mat, deltaR, deltaC);
        }
    }

    // traverse first col and last col
    for(int i = 0; i < n; i++) {
        // first col
        if(!vis[i][0] && mat[i][0] == 'O') {
            dfs(i, 0, vis, mat, deltaR, deltaC);
        }
        // last col
        if(!vis[i][m-1] && mat[i][m-1] == 'O') {
            dfs(i, m-1, vis, mat, deltaR, deltaC);
        }
    }

    // if unvisited O then convert to X
    for(int i=0; i < n; i++) {
        for(int j=0; j < m; j++) {
            if(!vis[i][j] && mat[i][j] == 'O')
            mat[i][j] = 'X';
        }
    }

    return mat;
}


int main() {

    vector<vector<char>> mat{
        {'X', 'X', 'X', 'X'}, 
        {'X', 'O', 'X', 'X'}, 
        {'X', 'O', 'O', 'X'}, 
        {'X', 'O', 'X', 'X'}, 
        {'X', 'X', 'O', 'O'}
    };

    // n = 5, m = 4
    vector<vector<char>> ans = fill(5, 4, mat);
    for(int i = 0;i < 5;i++) {
        for(int j = 0;j < 4;j++) {
            cout<<ans[i][j]<<" ";
        }
        cout<<"\n";
    }


    return 0;
}
