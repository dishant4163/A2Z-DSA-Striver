// 0/1 Knapsack | Recursion to Single Array Space Optimised Approach | DP on Subsequences



/*// Problem-Link->  https://www.naukri.com/code360/problems/0-1-knapsack_920542   



int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) {
	// Write your code here
	vector<int> prev(maxWeight+1, 0);
	// Base Case
	for(int W = weight[0]; W <= maxWeight; W++) prev[W] = value[0];

	for(int ind = 1; ind < n; ind++) {
		for(int cap = maxWeight; cap >= 0; cap--) {
			int notTake = prev[cap];
			int take = INT_MIN;
			if(weight[ind] <= cap) take = value[ind] + prev[cap - weight[ind]];

			prev[cap] = max(take, notTake);
		}
	}
	return prev[maxWeight];
}


*/




#include<bits/stdc++.h>
using namespace std;


// Soln-1 MEMORIZATION Approach
int memoHelp(int ind, int maxW, vector<int>& wt, vector<int>& val, vector<vector<int>>& dp) {
    // Base Case
    if(ind == 0) {
        if(wt[0] <= maxW) return val[0];
        else return 0;
    }

    if(dp[ind][maxW] != -1) return dp[ind][maxW];

    int notTake = memoHelp(ind-1, maxW, wt, val, dp);
    int take = INT_MIN;
    if(wt[ind] <= maxW) take = val[ind] + memoHelp(ind-1, maxW-wt[ind], wt, val, dp);

    return dp[ind][maxW] = max(take, notTake);
}

int knapsack_1(vector<int> weight, vector<int> value, int n, int maxWeight) {
	// Write your code here
    vector<vector<int>> dp(n, vector<int>(maxWeight+1, -1));
    return memoHelp(n-1, maxWeight, weight, value, dp);
}






// Soln-2 TABULATION Approach
int knapsack_2(vector<int> weight, vector<int> value, int n, int maxWeight) {
	// Write your code here
    vector<vector<int>> dp(n, vector<int>(maxWeight+1, 0));

    for(int W = weight[0]; W <= maxWeight; W++) dp[0][W] = value[0];

    for(int ind = 1; ind < n; ind++) {
        for(int W = 0; W <= maxWeight; W++) {
            int notTake = dp[ind - 1][W];
            int take = INT_MIN;
            if(weight[ind] <= W) take = value[ind] + dp[ind-1][W - weight[ind]];

            dp[ind][W] = max(take, notTake);
        }
    }
    return dp[n-1][maxWeight];
}







// Soln-3 SPACE OPTIMISATION Approach
// MOST OPtimised Soln (bcz we have single Array)
int knapsack_3(vector<int> weight, vector<int> value, int n, int maxWeight) {
	// Write your code here
    vector<int> prev(maxWeight+1, 0); // using Single Array to get Most OPtimised soln

    // Base Case
    for(int W = weight[0]; W <= maxWeight; W++) prev[W] = value[0];

    for(int ind = 1; ind < n; ind++) {
        for(int W = maxWeight; W >= 0; W--) {
            int notTake = prev[W];
            int take = INT_MIN;
            if(weight[ind] <= W) take = value[ind] + prev[W - weight[ind]];

            prev[W] = max(notTake, take);
        }
    }
    return prev[maxWeight];
}








int main() {

    vector<int> wt = {1, 2, 4, 5};
    vector<int> val = {5, 4, 8, 6};
    int maxW = 5;
    int n = wt.size();


// Soln-1 MEMORIZATION Approach
    cout << "Solve using MEMORIZATION Approach "<< endl;
    cout << "The Maximum value of items the thief can steal is: " << knapsack_1(wt, val, n, maxW) << endl << endl;



// Soln-2 TABULATION Approach
    cout << "Solve using TABULATION Approach "<< endl;
    cout << "The Maximum value of items the thief can steal is: " << knapsack_2(wt, val, n, maxW) << endl << endl;



// Soln-3 SPACE OPTIMISATION Approach
// MOST OPtimised Soln (bcz we have single Array)
    cout << "Solve using SPACE OPTIMISATION Approach "<< endl;
    cout << "The Maximum value of items the thief can steal is: " << knapsack_3(wt, val, n, maxW) << endl << endl;



    return 0;
}
