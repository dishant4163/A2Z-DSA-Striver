// Burst Balloons


/*// Problem-Link->  https://www.naukri.com/code360/problems/burst-balloons_628471  

int burstBalloons(vector<int> &arr){
    // Write your code here.
    int n = arr.size();

    arr.insert(arr.begin(), 1);
    arr.push_back(1);

    vector<vector<int>> dp(n+2, vector<int>(n+2, 0));

    for(int i = n; i >= 1; i--) {
        for(int j = 1; j <= n; j++) {
            if(i > j) continue; //base 

            int maxi = INT_MIN;
            for(int k = i; k <= j; k++) {
                int cost = arr[i-1] * arr[k] * arr[j+1] + dp[i][k-1] + dp[k+1][j];
                maxi = max(maxi, cost);
            }

            dp[i][j] = maxi;
        }
    }
    return dp[1][n];
}

*/



#include<bits/stdc++.h>
using namespace std;


// Soln-1 RECURSION Approach
int solve(int i, int j, vector<int>& arr) {
    // base case
    if(i > j) return 0;

    int maxi = INT_MIN;

    for(int ind = i; ind <= j; ind++) {
        int cost = arr[i-1]*arr[ind]*arr[j] + solve(i, ind-1, arr) + solve(ind+1, j, arr);

        maxi = max(maxi, cost);
    }

    return maxi;
}

int brustBalloons_1(vector<int> &arr) {
    int n = arr.size();

    arr.insert(arr.begin(), 1);
    arr.push_back(1);

    return solve(1, n, arr);
}






// Soln-2 MEMORIZATION Approach
int memo(int i, int j, vector<int>& arr, vector<vector<int>>& dp) {
    // base case
    if(i > j) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    int maxi = INT_MIN;

    for(int ind = i; ind <= j; ind++) {
        int cost = arr[i-1] * arr[ind] * arr[j+1] + memo(i, ind-1, arr, dp) + memo(ind+1, j, arr, dp);

        maxi = max(maxi, cost);
    }

    return dp[i][j] = maxi;
}

int brustBalloons_2(vector<int> &arr) {
    int n = arr.size();

    arr.insert(arr.begin(), 1);
    arr.push_back(1);

    vector<vector<int>> dp(n+1, vector<int>(n+1, -1));

    return memo(1, n, arr, dp);
}







// Soln-3 TABULATION Approach
int brustBalloons_3(vector<int> &arr) {
    int n = arr.size();

    arr.insert(arr.begin(), 1);
    arr.push_back(1);

    vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

    for(int i = n; i >= 1; i--) {
        for(int j = 1; j <= n; j++) {
            if(i > j) continue; // base case check

            int maxi = INT_MIN;
            for(int ind = i; ind <= j; ind++) {
                int cost = arr[i-1] * arr[ind] * arr[j+1] + dp[i][ind-1] + dp[ind+1][j];
                maxi = max(maxi, cost);
            }

            dp[i][j] = maxi;
        }
    }

    return dp[1][n];
}








int main() {

    vector<int> balloons = {3, 1, 5, 8};


// Soln-1 Recusrion Approach
    cout << "Solve using Recursion Approach "<< endl;
    cout << "Maximum coins obtained by brusting balloons is: " << brustBalloons_1(balloons) << endl << endl;



// Soln-2 MEMORIZATION Approach
    cout << "Solve using MEMORIZATION Approach "<< endl;
    cout << "Maximum coins obtained by brusting balloons is: " << brustBalloons_2(balloons) << endl << endl;



// Soln-3 TABULATION Approach
    cout << "Solve using TABULATION Approach "<< endl;
    cout << "Maximum coins obtained by brusting balloons is: " << brustBalloons_3(balloons) << endl << endl;





    return 0;
}

