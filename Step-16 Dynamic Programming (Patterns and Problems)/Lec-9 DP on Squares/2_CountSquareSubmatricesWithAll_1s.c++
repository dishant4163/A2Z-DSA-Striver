// Count Square Submatrices with All 1s | DP on Squares




/*// Problem-Link-> https://www.naukri.com/code360/problems/count-square-submatrices-with-all-ones_3751502  

int countSquares(int n, int m, vector<vector<int>> &arr) {
    // Write your code here.
    vector<vector<int>> dp(n, vector<int>(m, 0));

    for(int i = 0; i < n; i++) dp[i][0] = arr[i][0];
    for(int j = 0; j < m; j++) dp[0][j] = arr[0][j];

    for(int i = 1; i < n; i++) {
        for(int j = 1; j < m; j++) {
            if(arr[i][j] == 0) dp[i][j] = 0;
            else dp[i][j] = 1 + min({dp[i-1][j], dp[i-1][j-1], dp[i][j-1]});
        }
    }

    int sum = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++){
            sum += dp[i][j];
        }
    }

    return sum;
}

*/




#include <bits/stdc++.h>
using namespace std;

// Soln-> TABULATION Approach
int countSquares(int n, int m, vector<vector<int>> &arr) {
    vector<vector<int>> dp(n, vector<int>(m, 0));

    for(int i = 0; i < n; i++) dp[i][0] = arr[i][0];
    for(int j = 0; j < m; j++) dp[0][j] = arr[0][j];

    for(int i = 1; i < n; i++) {
        for(int j = 1; j < m; j++) {
            if(arr[i][j] == 0) dp[i][j] = 0;
            else {
                dp[i][j] = 1 + min({dp[i-1][j], dp[i-1][j-1], dp[i][j-1]});
            }
        }
    }

    int sum = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            sum += dp[i][j];
        }
    }

    return sum;
}



int main() {

    vector<vector<int>> arr = {
        {0, 1, 1, 1}, 
        {1, 1, 1, 1},
        {0, 1, 1, 1}
    };
    int n = 3, m = 4;

    cout << "Solve using TABULATION Approach " << endl;
    cout << "The Count Square Submatrices with All 1's is: " << countSquares(n, m, arr) << endl << endl;


    return 0;
}
