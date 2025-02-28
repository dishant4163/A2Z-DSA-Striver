// Minimum Coins



/*// Problem-Link-> https://www.naukri.com/code360/problems/minimum-elements_3843091 

#include <bits/stdc++.h> 
int minimumElements(vector<int> &num, int x) {
    // Write your code here.
    int n = num.size();
    vector<int> prev(x+1, 0), cur(x+1, 0);

    for(int t = 0; t <= x; t++) {
        if(t%num[0] == 0) prev[t] = t/num[0];
        else prev[t] = 1e9;
    }

    for(int ind = 1; ind < n; ind++) {
        for(int t = 0; t <= x; t++) {
            int notTake = prev[t];
            int take = 1e9;
            // we have infinte supplies of coins. So, 
            // we were still at current array index
            if(num[ind] <= t) take = 1 + cur[t - num[ind]];

            cur[t] = min(notTake, take); 
        }
        prev = cur;
    }

    int ans = prev[x];
    if(ans >= 1e9) return -1;
    else return ans;
}


*/



#include<bits/stdc++.h>
using namespace std;


// Soln-1 MEMORIZATION Approach
int memoHelp(int ind, int target, vector<int>& arr, vector<vector<int>>& dp) {
    // Base Case
    if(ind == 0) {
        if(target % arr[0] == 0) return target / arr[0];
        else return 1e9;
    }

    int notTake = 0 + memoHelp(ind-1, target, arr, dp);
    int take = 1e9;
    if(arr[ind] <= target) take = 1 + memoHelp(ind , target - arr[ind], arr, dp);

    return dp[ind][target] = min(notTake, take);
}

int minimumElements_1(vector<int>& arr, int T) {
	// Write your code here
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(T+1, -1));

    int ans = memoHelp(n-1, T, arr, dp);

    if(ans >= 1e9) return -1;
    else return ans;
}






// Soln-2 TABULATION Approach
int minimumElements_2(vector<int>& arr, int target) {
	// Write your code here
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(target+1, 0));

    // Base Case
    for(int T = 0; T <= target; T++) {
        if(T % arr[0] == 0) dp[0][T] = T / arr[0];
        else dp[0][T] = 1e9;
    }

    for(int ind = 1; ind < n; ind++) {
        for(int T = 0; T <= target; T++) {
            int notTake = 0 + dp[ind-1][T];
            int take = 1e9;
            if(arr[ind] <= T) take = 1 + dp[ind][T - arr[ind]];

            dp[ind][T] = min(notTake, take);
        }
    }

    int ans = dp[n-1][target];
    if(ans >= 1e9) return -1;
    else return ans;
}





// Soln-3 SPACE OPTIMISATION Approach
int minimumElements_3(vector<int>& arr, int target) {
	// Write your code here
    int n = arr.size();
    vector<int> prev(target+1, 0), cur(target+1, 0);

    for(int T = 0; T <= target; T++) {
        if(T%arr[0] == 0) prev[T] = T/arr[0];
        else prev[T] = 1e9;
    }

    for(int ind = 1; ind < n; ind++) {
        for(int T = 0; T <= target; T++) {
            int notTake = 0 + prev[T];
            int take = 1e9;
            // we have infinte supplies of coins. So, we were still 
            // at current array index 
            if(arr[ind] <= T) take = 1 + cur[T - arr[ind]];

            cur[T] = min(notTake, take);
        }
        prev = cur;
    }

    int ans = prev[target];

    if(ans >= 1e9) return -1;
    else return ans;
}





int main() {

    vector<int> arr = {1, 2, 3};
    int T = 7;


// Soln-1 MEMORIZATION Approach
    cout << "Solve using MEMORIZATION Approach "<< endl;
    cout << "The minimum number of coins required to form the target sum is " << minimumElements_1(arr, T) << endl << endl;



// Soln-2 TABULATION Approach
    cout << "Solve using TABULATION Approach "<< endl;
    cout << "The minimum number of coins required to form the target sum is " << minimumElements_2(arr, T) << endl << endl;



// Soln-3 SPACE OPTIMISATION Approach
    cout << "Solve using SPACE OPTIMISATION Approach "<< endl;
    cout << "The minimum number of coins required to form the target sum is " << minimumElements_3(arr, T) << endl << endl;



    return 0;
}
