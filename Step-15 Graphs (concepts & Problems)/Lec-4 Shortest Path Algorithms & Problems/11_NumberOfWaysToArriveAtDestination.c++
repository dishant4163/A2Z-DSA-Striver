// Number of Ways to Arrive at Destination


/*// Problem(gfg)-

You are in a city that consists of n intersections numbered from 0 to n - 1 with bi-directional roads between some intersections.
The inputs are generated such that you can reach any intersection from any other intersection and that there is at most one road between any two intersections.

You are given an integer n and a 2D integer array roads where roads[i] = [ui, vi, timei] means that there is a road between 
intersections ui and vi that takes timei minutes to travel. You want to know in how many ways you can travel from intersection 0 to intersection n - 1 in the shortest amount of time.

Return the number of ways you can arrive at your destination in the shortest amount of time. Since the answer may be large, return it modulo (10^9 + 7).

Input:
n=7, m=10
edges= [[0,6,7], [0,1,2], [1,2,3], [1,3,3], [6,3,3], [3,5,1], [6,5,1], [2,5,1], [0,4,5], [4,6,2]]

Output:
4
Explaination:

The four ways to get there in 7 minutes are:
- 0  6
- 0  4  6
- 0  1  2  5  6
- 0  1  3  5  6

*/



#include<bits/stdc++.h>
using namespace std;


int countPaths(int n, vector<vector<int>> &roads) {
    // 1st create adjList of pairs for bi-directional(UG)
    vector<pair<int, int>> adj[n];
    for(auto it : roads) {
        adj[it[0]].push_back({it[1], it[2]});
        adj[it[1]].push_back({it[0], it[2]});
    }

    int mod = (int)(1e9 + 7);

    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int>> > pq;
    pq.push({0, 0}); // {distance, node}

    vector<int> dist(n, 1e9), ways(n, 0);
    dist[0] = 0; // mark srcNode as 0
    ways[0] = 1; // marks 1st i.e, srcNode to be having 1 way in-starting

    while(!pq.empty()) {
        int curDist = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for(auto it : adj[node]) {
            int adjNode = it.first;
            int edgeWt = it.second;

            //this is the 1st time i am reached with this shortest distanc
            if(curDist + edgeWt < dist[adjNode]) {
                dist[adjNode] = curDist + edgeWt;
                pq.push({curDist + edgeWt, adjNode});
                ways[adjNode] = ways[node];
            }
            // If we again encounter a node with the same short distance
            // as before, we simply increment the no. of ways.
            else if(curDist + edgeWt == dist[adjNode]) {
                ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
            }
        }
    }

    return ways[n - 1] % mod;
}


int main() {

    int n = 7;
    vector<vector<int>> edges = {{0, 6, 7}, {0, 1, 2}, {1, 2, 3}, {1, 3, 3}, {6, 3, 3}, 
    {3, 5, 1}, {6, 5, 1}, {2, 5, 1}, {0, 4, 5}, {4, 6, 2}};

    int ans = countPaths(n, edges);

    cout << "Number of counts of ways to arrive destination with shortest distance is: " << ans;
    cout << endl;



    return 0;
}

