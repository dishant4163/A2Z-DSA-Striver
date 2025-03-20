// Path With Minimum Effort



/* // Problem-Link-> https://www.naukri.com/code360/problems/path-with-minimum-effort_1380958


int minimumTimeTakingPath(vector<vector<int>> &heights) {
    // Write your code here.
    int n = heights.size(), m = heights[0].size();

    priority_queue<pair<int, pair<int, int> >, 
    vector<pair<int, pair<int,int>> >, 
    greater<pair<int, pair<int, int>>> > pq;
    pq.push({0, {0, 0}}); // {diff, {row, col}}

    vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
    dist[0][0] = 0;

    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, 1, 0, -1};

    while(!pq.empty()) {
        int diff = pq.top().first;
        int curRow = pq.top().second.first;
        int curCol = pq.top().second.second;
        pq.pop();

        if(curRow == n-1 && curCol == m-1) return diff;

        for(int i=0; i < 4; i++) {
            int nr = curRow + dr[i];
            int nc = curCol + dc[i];

            if(nr >=0 && nr < n && nc >= 0 && nc < m) {
                int newEffort = max(abs(heights[curRow][curCol] - heights[nr][nc]), diff);
                if(newEffort < dist[nr][nc]) {
                    dist[nr][nc] = newEffort;
                    pq.push({newEffort, {nr, nc}});
                }
            }
        }
    }

    return 0;
}

*/


#include<bits/stdc++.h>
using namespace std;


int MinimumEffort(vector<vector<int>> &heights) {
    int n = heights.size(), m = heights[0].size();

    // declare the pq => {difference, {row, col}}
    priority_queue<pair<int, pair<int, int>>, 
    vector<pair<int, pair<int, int>> >, 
    greater<pair<int, pair<int, int>>> > pq;
    pq.push({0, {0, 0}}); // {diff, {row, col}}

    vector<vector<int>> dist(n, vector<int>(m, 1e9));
    dist[0][0] = 0;

    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, 1, 0, -1};

    while(!pq.empty()) {
        int diff = pq.top().first;
        int curRow = pq.top().second.first;
        int curCol = pq.top().second.second;
        pq.pop();

        // if the current row & col is may be the answer
        if(curRow == n-1 && curCol == m-1) return diff;

        for(int i=0; i < 4; i++) {
            int nr = curRow + dr[i];
            int nc = curCol + dc[i];

            if(nr >= 0 && nr < n && nc >=0 && nc < m) {
                int newEffort = max(abs(heights[curRow][curCol] - heights[nr][nc]), diff);

                if(newEffort < dist[nr][nc]) {
                    dist[nr][nc] = newEffort;
                    pq.push({newEffort, {nr, nc}});
                }
            }
        }
    }

    return 0;
}



int main() {

    vector<vector<int>> heights = {{1, 2, 2}, {3, 8, 2}, {5, 3, 5}};

    int ans = MinimumEffort(heights);
    cout << "The output is: " << ans;
    cout << endl;


    return 0;
}
