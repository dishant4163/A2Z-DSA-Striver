// Find the City With the Smallest Number of Neighbours at a Threshold Distance


/*// Problem-Link->  https://www.naukri.com/code360/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance_1264289


#include <bits/stdc++.h> 
int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold) {
	// Write your code here
	vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
    for(auto it : edges) {
        dist[it[0]][it[1]] = it[2];
        dist[it[1]][it[0]] = it[2];
    }

    for(int i=0; i < n; i++) dist[i][i] = 0;

    for(int k = 0; k < n; k++) {
        for(int i=0; i < n; i++) {
            for(int j=0; j < n; j++) {
                if(dist[i][k] == INT_MAX || dist[k][j] == INT_MAX) continue;

                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    int cntCity = n, cityNo = -1;
    for(int city = 0; city < n; city++) {
        int cnt = 0;
        for(int adjCity = 0; adjCity < n; adjCity++) {
            if(dist[city][adjCity] <= distanceThreshold) cnt++;
        }

        if(cnt <= cntCity) {
            cntCity = cnt;
            cityNo = city;
        }
    }

    return cityNo;
}

*/



#include<bits/stdc++.h>
using namespace std;

int findCity(int n, int m, vector<vector<int>>& edges, int distanceThreshold) {
    vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
    for(auto it : edges) {
        dist[it[0]][it[1]] = it[2];
        dist[it[1]][it[0]] = it[2];
    }

    for(int i=0; i < n; i++) dist[i][i] = 0;

    for(int k = 0; k < n; k++) {
        for(int i=0; i < n; i++) {
            for(int j=0; j < n; j++) {
                if(dist[i][k] == INT_MAX || dist[k][j] == INT_MAX) continue;

                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    int cntCity = n, cityNo = -1;
    for(int city = 0; city < n; city++) {
        int cnt = 0;
        for(int adjCity = 0; adjCity < n; adjCity++) {
            if(dist[city][adjCity] <= distanceThreshold) cnt++;
        }

        if(cnt <= cntCity) {
            cntCity = cnt;
            cityNo = city;
        }
    }

    return cityNo;
}


int main() {

    int n = 4;
	int m = 4;
	vector<vector<int>> edges = {{0, 1, 3}, {1, 2, 1}, {1, 3, 4}, {2, 3, 1}};
	int distanceThreshold = 4;

	int cityNo = findCity(n, m, edges, distanceThreshold);
	cout << "The answer is node: " << cityNo << endl;


    return 0;
}
