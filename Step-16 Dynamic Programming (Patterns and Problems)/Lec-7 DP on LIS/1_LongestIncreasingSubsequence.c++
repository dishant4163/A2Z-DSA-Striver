// Longest Increasing Subsequence



/* // Problem-Link->  https://www.naukri.com/code360/problems/longest-increasing-subsequence_630459 

int longestIncreasingSubsequence(int arr[], int n){
    // Write Your Code here
    vector<int> cur(n+1, 0), next(n+1, 0);

    for(int index = n-1; index >= 0; index--) {
        for(int prevInd = index-1; prevInd >= -1; prevInd--) {
            int notTake = 0 + next[prevInd+1];
            int take = 0;
            if(prevInd == -1 || arr[index] > arr[prevInd]) {
                take = 1 + next[index+1];
            }
            cur[prevInd+1] = max(notTake, take);
        }
        next = cur;
    }
    return next[0];
}

*/



#include<bits/stdc++.h>
using namespace std;


// Soln-1 MEMORIZATION Approach
int memo(int index, int prevIndex, int arr[], int n, vector<vector<int>>& dp) {
    // Base Case
    if(index == n) return 0;

    if(dp[index][prevIndex+1] != -1) return dp[index][prevIndex+1];

    int notTake = 0 + memo(index+1, prevIndex, arr, n, dp);

    int take = 0;
    if(prevIndex == -1 || arr[index] > arr[prevIndex]) {
        take = 1 + memo(index+1, index, arr, n, dp);
    }

    return dp[index][prevIndex+1] = max(notTake, take);
}

int longestIncreasingSubsequence_1(int arr[], int n) {
    vector<vector<int>> dp(n, vector<int>(n+1, -1));

    return memo(0, -1, arr, n, dp);
}





// Soln-2 TABULATION Approach
int longestIncreasingSubsequence_2(int arr[], int n) {
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

    for(int ind = n-1; ind >= 0; ind--) {
        for(int prevInd = ind-1; prevInd >= -1; prevInd--) {
            int notTake = 0 + dp[ind+1][prevInd + 1];
            int take = 0;

            if(prevInd == -1 || arr[ind] > arr[prevInd]) {
                take = 1 + dp[ind+1][ind+1];
            }

            dp[ind][prevInd+1] = max(notTake, take);
        }
    }

    return dp[0][0];
}





// Soln-3 SPACE OPTIMISATION Approach
int longestIncreasingSubsequence_3(int arr[], int n) {
    vector<int> cur(n+1, 0), next(n+1, 0);

    for(int ind = n-1; ind >= 0; ind--) {
        for(int prevInd = ind-1; prevInd >= -1; prevInd--) {
            int notTake = 0 + next[prevInd + 1];

            int take = 0;
            if(prevInd == -1 || arr[ind] > arr[prevInd]) {
                take = 1 + next[ind+1];
            }

            cur[prevInd+1] = max(notTake, take);
        }
        next = cur;
    }

    return next[0];
}



int main() {

    int arr[] = {10, 9, 2, 5, 3, 7, 101, 18};
    int n = sizeof(arr) / sizeof(arr[0]);

// Soln-1 MEMORIZATION Approach
    cout << "Solve using MEMORIZATION Approach "<< endl;
    cout << "The length of the longest increasing subsequence is " << longestIncreasingSubsequence_1(arr, n) << endl << endl;



// Soln-2 TABULATION Approach
    cout << "Solve using TABULATION Approach "<< endl;
    cout << "The length of the longest increasing subsequence is " << longestIncreasingSubsequence_2(arr, n) << endl << endl;



// Soln-3 SPACE OPTIMISATION Approach
    cout << "Solve using SPACE OPTIMISATION Approach "<< endl;
    cout << "The length of the longest increasing subsequence is " << longestIncreasingSubsequence_3(arr, n) << endl << endl;


    return 0;
}

