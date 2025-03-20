// Rotten Oranges : Min time to rot all oranges : BFS


/* // Link-> https://www.naukri.com/code360/problems/rotting-oranges_701655


#include<queue>
int minTimeToRot(vector<vector<int>>& grid, int n, int m){
    // Write your code here.
    queue<pair<pair<int,int>, int>> q;
    int cntFresh = 0, vis[n][m];

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(grid[i][j] == 2) {
                q.push({{i,j}, 0});
                vis[i][j] = 2;
            }
            else {
                vis[i][j] = 0;
            }

            if(grid[i][j] == 1) cntFresh++;
        }
    }

    int maxTime = 0, cnt = 0;
    int deltaR[] = {-1, 0, 1, 0};
    int deltaC[] = {0, 1, 0, -1};

    while(!q.empty()) {
        int r = q.front().first.first;
        int c = q.front().first.second;
        int t = q.front().second;
        q.pop();
        maxTime = max(maxTime, t);

        for(int i=0; i < 4; i++) {
            int nR = r + deltaR[i];
            int nC = c + deltaC[i];

            if(nR >= 0 && nR < n && nC >= 0 && nC < m 
            && grid[nR][nC] == 1 && vis[nR][nC] == 0) {
                q.push({{nR,nC}, t+1});
                vis[nR][nC] = 2;
                cnt++;
            }
        }
    }

    return (cnt != cntFresh) ? -1 : maxTime;
}


*/



#include<bits/stdc++.h>
using namespace std;


int orangesRotting(vector<vector<int>>& grid) {
    int n = grid.size(), m = grid[0].size(), cntFresh = 0;
    queue<pair <pair<int, int>, int>> q;
    int vis[n][m];

    for(int i=0; i < n; i++) {
        for(int j=0; j < m; j++) {
            if(grid[i][j] == 2) {
                q.push({{i, j}, 0});
                vis[i][j] = 2;
            } 
            else {
                vis[i][j] = 0;
            }

            if(grid[i][j] == 1) cntFresh++;;
        }
    }

    int maxTime = 0, cnt = 0;
    int deltaR[] = {-1, 0, 1, 0};
    int deltaC[] = {0, 1, 0, -1};

    while(!q.empty()) {
        int r = q.front().first.first;
        int c = q.front().first.second;
        int t = q.front().second;
        q.pop();

        maxTime = max(maxTime, t);

        for(int i=0; i < 4; i++) {
            int nR = r + deltaR[i];
            int nC = c + deltaC[i];

            if(nR >= 0 && nR < n && nC >= 0 && nC < m 
            && grid[nR][nC] == 1 && vis[nR][nC] == 0) {
                q.push({{nR, nC}, t + 1});
                vis[nR][nC] = 2;
                cnt++;
            }
        }
    }

    return (cnt != cntFresh) ? -1 : maxTime;
}


int main() {

    vector<vector<int>> v{ {2,1,1} , {1,1,0} , {0,1,1} } ;
    int rotting = orangesRotting(v);
    cout<<"Minimum Number of Minutes Required "<<rotting<<endl;


    return 0;
}
