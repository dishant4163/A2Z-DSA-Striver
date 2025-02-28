// UnBounded Knapsack


/*//Problem-Link-> https://www.naukri.com/code360/problems/unbounded-knapsack_1215029    

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    // Write Your Code Here.
    vector<int> prev(w+1, 0);

    for(int i = weight[0]; i <= w; i++) {
        prev[i] = (i/weight[0]) * profit[0];
    }

    for(int ind = 1; ind < n; ind++) {
        for(int wt = 0; wt <= w; wt++) {
            int notTake = 0 + prev[wt];
            int take = -1e9;
            if(weight[ind] <= wt) take = profit[ind] + prev[wt - weight[ind]];

            prev[wt] = max(notTake, take);
        }
    }
    return prev[w];
}

*/



#include<bits/stdc++.h>
using namespace std;


// Soln-1 MEMORIZATION Approach
int memoHelp(int ind, int maxW, vector<int>& val, vector<int>& wt, vector<vector<int>> &dp) {
    //Base Case
    if(ind == 0) {
        return (maxW/wt[0]) * val[0];
    }

    if(dp[ind][maxW] != -1) return dp[ind][maxW];

    int notTake = 0 + memoHelp(ind-1, maxW, val, wt, dp);
    int take = -1e9;
    if(wt[ind] <= maxW) take = val[ind] + memoHelp(ind, maxW - wt[ind], val, wt, dp);

    return dp[ind][maxW] = max(take, notTake);
}

int unboundedKnapsack_1(int n, int maxW, vector<int>& val, vector<int>& wt) {
    vector<vector<int>> dp(n, vector<int>(maxW+1, -1));

    return memoHelp(n-1, maxW, val, wt, dp);
}





// Soln-2 TABULATION Approach
int unboundedKnapsack_2(int n, int maxW, vector<int>& val, vector<int>& wt) {
    vector<vector<int>> dp(n, vector<int>(maxW+1, 0));

    // Base Case 
    for(int W = wt[0]; W <= maxW; W++) {
        dp[0][W] = (W / wt[0]) * val[0];
    }

    for(int ind=1; ind < n; ind++) {
        for(int W = 0; W <= maxW; W++) {
            int notTake = 0 + dp[ind-1][W];
            int take = -1e9;
            if(wt[ind] <= W) take = val[ind] + dp[ind][W - wt[ind]];

            dp[ind][W] = max(notTake, take);
        }
    }
    return dp[n-1][maxW];
}





// Soln-3 SPACE OPTIMISATION Approach
int unboundedKnapsack_3(int n, int maxW, vector<int>& val, vector<int>& wt) {
    vector<int> prev(maxW+1, 0);

    for(int W = wt[0]; W <= maxW; W++) prev[W] = (W/wt[0]) * val[0];

    for(int ind = 1; ind < n; ind++) {
        for(int W = 0; W <= maxW; W++) {
            int notTake = 0 + prev[W];
            int take = -1e9;
            if(wt[ind] <= W) take = val[ind] + prev[W - wt[ind]];

            prev[W] = max(take, notTake);
        }
    }
    return prev[maxW];
}









int main() {

    vector<int> wt = {2, 4, 6}; // Weight of items
    vector<int> val = {5, 11, 13}; // Value of items
    int W = 10; // Max-Weight capacity of the knapsack
    int n = wt.size(); // Number of items


// Soln-1 MEMORIZATION Approach
    cout << "Solve using MEMORIZATION Approach "<< endl;
    cout << "The Maximum value of items the thief can steal is: " << unboundedKnapsack_1(n, W, val, wt) << endl << endl;



// Soln-2 TABULATION Approach
    cout << "Solve using TABULATION Approach "<< endl;
    cout << "The Maximum value of items the thief can steal is: " << unboundedKnapsack_2(n, W, val, wt) << endl << endl;



// Soln-3 SPACE OPTIMISATION Approach
    cout << "Solve using SPACE OPTIMISATION Approach "<< endl;
    cout << "The Maximum value of items the thief can steal is: " << unboundedKnapsack_3(n, W, val, wt) << endl << endl;




    return 0;
}



