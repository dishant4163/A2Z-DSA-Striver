// Coin Change 2 



/*// Problem-Link-> https://www.naukri.com/code360/problems/ways-to-make-coin-change_630471   

#include<bits/stdc++.h>

long countWaysToMakeChange(int *denominations, int n, int value) {
    //Write your code here
    vector<long> prev(value+1, 0), cur(value+1, 0);

    for(int i = 0; i <= value; i++) {
        prev[i] = (i % denominations[0] == 0);
    }

    for(int ind = 1; ind < n; ind++) {
        for(int target = 0; target <= value; target++) {
            long notTake = prev[target];
            long take = 0; 
            if(denominations[ind] <= target) take = cur[target - denominations[ind]];

            cur[target] = notTake + take;
        }
        prev = cur;
    }
    return prev[value];
}


*/



#include<bits/stdc++.h>
using namespace std;


// Soln-1 MEMORIZATION Approach
long memoHelp(int ind, int tar, vector<int>& arr, vector<vector<long>>& dp) {
    //Base Case
    if(ind == 0) return (tar % arr[0] == 0);

    if(dp[ind][tar] != -1) return dp[ind][tar];

    long notTake = memoHelp(ind-1, tar, arr, dp);
    long take = 0;
    if(arr[ind] <= tar) take = memoHelp(ind, tar - arr[ind], arr, dp);

    return dp[ind][tar] = notTake + take;
}

long countWaysToMakeChange_1(vector<int>& arr, int n, int T) {
    vector<vector<long>> dp(n, vector<long>(T+1, -1));

    return memoHelp(n-1, T, arr, dp);
}





// Soln-2 TABULATION Approach
long countWaysToMakeChange_2(vector<int>& arr, int n, int T) {
    vector<vector<long>> dp(n, vector<long>(T+1, 0));

    // Base Case
    for(int tar = 0; tar <= T; tar++) {
        if (tar % arr[0] == 0) dp[0][tar] = 1;
    }

    for(int ind = 1; ind < n; ind++) {
        for(int tar = 0; tar <= T; tar++) {
            long notTake = dp[ind-1][tar];
            long take = 0;
            if(arr[ind] <= tar) take = dp[ind][tar - arr[ind]];

            dp[ind][tar] = notTake + take;
        }
    }
    return dp[n-1][T];
}





// Soln-3 SPACE OPTIMISATION Approach
long countWaysToMakeChange_3(vector<int>& arr, int n, int T) {
    vector<int> prev(T+1, 0), cur(T+1, 0);

    for(int tar = 0; tar <= T; tar++) {
        prev[tar] = (tar % arr[0] == 0);
    }

    for(int ind = 1; ind < n; ind++) {
        for(int target = 0; target <= T; target++) {
            long notTake = prev[target];
            long take = 0;
            if(arr[ind] <= target) take = cur[target - arr[ind]];

            cur[target] = notTake + take;
        }
        prev = cur;
    }
    return prev[T];
}









int main() {

    vector<int> arr = {1, 2, 3};
    int target = 4;
    int n = arr.size();


// Soln-1 MEMORIZATION Approach
    cout << "Solve using MEMORIZATION Approach "<< endl;
    cout << "The total number of ways is: " << countWaysToMakeChange_1(arr, n, target) << endl << endl;



// Soln-2 TABULATION Approach
    cout << "Solve using TABULATION Approach "<< endl;
    cout << "The total number of ways is: " << countWaysToMakeChange_2(arr, n, target) << endl << endl;



// Soln-3 SPACE OPTIMISATION Approach
    cout << "Solve using SPACE OPTIMISATION Approach "<< endl;
    cout << "The total number of ways is: " << countWaysToMakeChange_3(arr, n, target) << endl << endl;




    return 0;
}
