// Minimum Multiplications to Reach End OR
// Minimum steps to reach end from start by performing multiplication and mod operations with array elements




#include<bits/stdc++.h>
using namespace std;


int minimumMultiplications(vector<int> &arr, int start, int end) {
    int mod = 100000;
    queue<pair<int, int>> q;
    q.push({start, 0}); // {srcNode, steps}

    vector<int> dist(100000, 1e9);
    dist[start] = 0;

    while(!q.empty()) {
        int node = q.front().first;
        int steps = q.front().second;
        q.pop();

        for(auto it : arr) {
            int num = (it * node) % mod;
            // If the no. of multiplications are less than before
            // in order to reach a number, we update the dist array.
            if(steps + 1 < dist[num]) {
                dist[num] = steps + 1;

                // Whenever we reach the end number
                // return the calculated steps
                if(num == end) return steps + 1;
                q.push({num, steps + 1});
            }
        }
    }

    return -1;
}



int main() {

    int start = 3, end = 30;
    vector<int> arr = {2, 5, 7};

    int ans = minimumMultiplications(arr, start, end);

    cout << "The Minimum Multiplications to Reach End is: " << ans;
    cout << endl;


    return 0;
}
