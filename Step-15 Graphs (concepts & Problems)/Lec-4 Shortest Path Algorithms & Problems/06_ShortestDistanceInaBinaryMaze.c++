// Shortest Distance in a Binary Maze



/* // Problem-Link-> https://www.naukri.com/code360/problems/shortest-path-in-a-binary-maze_893065 


#include<bits/stdc++.h>

int shortestPathBinaryMatrix(vector<vector<int>> &matrix, pair<int, int> src, pair<int, int> dest) {
    // Write your code here

    // Edge Case-1
    if(matrix[src.first][src.second] == 0 || matrix[dest.first][dest.second] == 0) return -1;
    // Edge Case-2
    if(src.first == dest.first && src.second == dest.second) return 0;

    int n = matrix.size(), m = matrix[0].size();

    queue<pair<int, pair<int, int>>> q;
    q.push({0, {src.first, src.second}});

    vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
    dist[src.first][src.second] = 0;

    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, 1, 0, -1};

    while(!q.empty()) {
        int wt = q.front().first;
        int r = q.front().second.first;
        int c = q.front().second.second;
        q.pop();

        for(int i=0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if(nr >= 0 && nr < n && nc >= 0 && nc < m && wt+1<dist[nr][nc] && matrix[nr][nc] == 1) {
                dist[nr][nc] = wt + 1;
                if(nr == dest.first && nc == dest.second) return wt+1;
                q.push({dist[nr][nc], {nr, nc}});
            }
        }
    }

    return -1;
}

*/



#include<bits/stdc++.h>
using namespace std;


int shortestPath(vector<vector<int>> &grid, pair<int, int> source, pair<int, int> destination) {
    // Edge Case-1: if the source is only the destination
    if(source.first == destination.first && 
    source.second == destination.second) {
        return 0;
    }
    // Edge Case-2
    if(grid[source.first][source.second] == 0 || 
    grid[destination.first][destination.second] == 0) return 0;

    int n = grid.size(), m = grid[0].size();

    // declare Queue
    queue<pair<int, pair<int,int>> > q;
    q.push({0, {source.first, source.second}});

    vector<vector<int>> dist(n, vector<int> (m, 1e9));
    dist[source.first][source.second] = 0;

    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, 1, 0, -1};

    while(!q.empty()) {
        auto it = q.front();
        q.pop();

        int dis = it.first;
        int r = it.second.first;
        int c = it.second.second;

        for(int i=0; i < 4; i++) {
            int newr = r + dr[i];
            int newc = c + dc[i];

            if (newr >= 0 && newr < n && newc >= 0 && newc < m &&
            grid[newr][newc] == 1 && dis + 1 < dist[newr][newc]) {
                dist[newr][newc] = dis + 1;

                // return the distance until the point when we 
                // encounter the destination cell
                if(newr == destination.first && newc == destination.second) {
                    return dis + 1;
                }

                q.push({1+dis, {newr, newc}});
            }
        }
    }

    // If no path is found from source to destination.
    return -1;

}




int main() {

    pair<int, int> source, destination;
    source.first = 0;
    source.second = 1;
    destination.first = 2;
    destination.second = 2;

    vector<vector<int>> grid = {{1, 1, 1, 1},
                                {1, 1, 0, 1},
                                {1, 1, 1, 1},
                                {1, 1, 0, 0},
                                {1, 0, 0, 1}};

    int res = shortestPath(grid, source, destination);
    cout << "The output is: " << res;
    cout << endl;


    return 0;
}
