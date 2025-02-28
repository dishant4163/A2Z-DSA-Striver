// Partition Array for Maximum Sum | Front Partition


/*// Problem-Link->  https://www.naukri.com/code360/problems/partition-array-for-maximum-sum_3755255  

int maximumSubarray(vector<int> &arr, int k){
    // Write your code here.
    int n = arr.size();

    vector<int> dp(n+1, 0);
    dp[n] = 0; // base case

    for(int ind = n-1; ind >= 0; ind--) {
        int len = 0;
        int maxi = INT_MIN, maxAns = INT_MIN;

        for(int j = ind; j < min(ind+k, n); j++) {
            len++;
            maxi = max(maxi, arr[j]);
            int sum = len*maxi + dp[j+1];
            maxAns = max(maxAns, sum);
        }

        dp[ind] = maxAns;
    }

    return dp[0];
}

*/



#include<bits/stdc++.h>
using namespace std;


// Soln-1 RECURSION Approach
int solve(int ind, int k, vector<int>& num) {
    int n = num.size();

    // base case
    if(ind == n) return 0;
    int len = 0, maxi = INT_MIN, maxAns = INT_MIN;

    for(int j = ind; j < min(n, ind + k); j++) {
        len++;
        maxi = max(maxi, num[j]);
        int sum = len * maxi + solve(j+1, k, num);
        maxAns = max(maxAns, sum);
    }

    return maxAns;
}
int maxSumAfterPartitioning_1(vector<int>& num, int k) {
    int n = num.size();

    return solve(0, k, num);
}







// Soln-2 MEMORIZATION Approach
int memo(int ind, int k, vector<int>& num, vector<int>& dp) {
    int n = num.size();

    // base case 
    if(ind == n) return 0;

    if(dp[ind] != -1) return dp[ind];

    int len = 0, maxi = INT_MIN, maxAns = INT_MIN;

    for(int j = ind; j < min(n, ind+k); j++) {
        len++;
        maxi = max(maxi, num[j]);
        int sum = len * maxi + memo(j+1, k, num, dp);
        maxAns = max(maxAns, sum);
    }

    return dp[ind] = maxAns;
}

int maxSumAfterPartitioning_2(vector<int>& num, int k) {
    int n = num.size();

    vector<int> dp(n, -1);
    return memo(0, k, num, dp);
}








// Soln-3 TABULATION Approach
int maxSumAfterPartitioning_3(vector<int>& num, int k) {
    int n = num.size();

    vector<int> dp(n+1, 0);
    dp[n] = 0; // base case

    for(int ind = n-1; ind >= 0; ind--) {
        int len = 0;
        int maxi = INT_MIN, maxAns = INT_MIN;

        for(int j = ind; j < min(ind+k, n); j++) {
            len++;
            maxi = max(maxi, num[j]);
            int sum = len*maxi + dp[j+1];
            maxAns = max(maxAns, sum);
        }

        dp[ind] = maxAns;
    }

    return dp[0];
}






int main() {

    vector<int> num = {1, 15, 7, 9, 2, 5, 10};
    int k = 3; 


// Soln-1 RECURSION Approach
    cout << "Solve using RECURSION Approach " << endl;
    cout << "The maximum sum is: " << maxSumAfterPartitioning_1(num, k) << endl << endl;



// Soln-2 MEMORIZATION Approach
    cout << "Solve using MEMORIZATION Approach " << endl;
    cout << "The maximum sum is: " << maxSumAfterPartitioning_2(num, k) << endl << endl;



// Soln-3 TABULATION Approach
    cout << "Solve using TABULATION Approach " << endl;
    cout << "The maximum sum is: " << maxSumAfterPartitioning_3(num, k) << endl << endl;





    return 0;
}

