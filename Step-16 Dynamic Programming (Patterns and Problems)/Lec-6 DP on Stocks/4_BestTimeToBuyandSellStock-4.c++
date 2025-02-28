// Best Time to Buy and Sell Stock-4
// this problem is ditto same as "Buy and Sell Stock-3" in which we have atmost 2 transactions
// but in this we have k transaction


/*// Problem-Link->   https://www.naukri.com/code360/problems/best-time-to-buy-and-sell-stock_1080698

#include <bits/stdc++.h> 
int maximumProfit(vector<int> &prices, int n, int k) {
    // Write your code here.
    vector<int> cur(2*k+1, 0), ahead(2*k+1, 0);

    for(int index = n-1; index >= 0; index--) {
        for(int tranNo = 2*k-1; tranNo >= 0; tranNo--) {
            if(tranNo%2 == 0) {
                cur[tranNo] = max(-prices[index] + ahead[tranNo+1], 0 + ahead[tranNo]);
            }
            else {
                cur[tranNo] = max(prices[index] + ahead[tranNo+1], 0 + ahead[tranNo]);
            }
        }
        ahead = cur;
    }

    return ahead[0];
}


*/


#include<bits/stdc++.h>
using namespace std;



// Soln-1 MEMORIZATION Approach
int memo(int ind, int tranNo, vector<int> &val, int n, int k, vector<vector<int>>& dp) {
    //base case 
    if(ind == n || tranNo == 2*k) return 0;

    if(dp[ind][tranNo] != -1) return dp[ind][tranNo];

    if(tranNo % 2 == 0) { // buy
        return dp[ind][tranNo] = max(-val[ind] + memo(ind+1, tranNo+1, val, n, k, dp),
                    0 + memo(ind+1, tranNo, val, n, k, dp)); 
    }
    else {
        return dp[ind][tranNo] = max(val[ind] + memo(ind+1, tranNo+1, val, n, k, dp),
                    0 + memo(ind+1, tranNo, val, n, k, dp));
    }
}

int maximumProfit_1(vector<int>&prices, int n, int k) {
    vector<vector<int>> dp(n, vector<int>(2*k+1, -1));
    return memo(0, 0, prices, n, k, dp);
}






// Soln-2 TABULATION Approach
int maximumProfit_2(vector<int>&prices, int n, int k) {
    vector<vector<int>> dp(n+1, vector<int>(2*k+1, 0));

    for(int i = n-1; i >= 0; i--) {
        for(int tranNo = 2*k-1; tranNo >= 0; tranNo--) {
            if(tranNo % 2 == 0) { // Buy
                dp[i][tranNo] = max(-prices[i] + dp[i+1][tranNo+1], 0 + dp[i+1][tranNo]);
            }
            else {
                dp[i][tranNo] = max(prices[i] + dp[i+1][tranNo+1], 0 + dp[i+1][tranNo]);
            }
        }
    }

    return dp[0][0]; //initail starting of index = 0, transactio no = 0
}



// Soln-3 SPACE OPTIMISATION Approach
int maximumProfit_3(vector<int>&prices, int n, int k) {
    vector<int> cur(2*k+1, 0), ahead(2*k+1, 0);

    for(int i = n-1; i >= 0; i--) {
        for(int tranNo = 2*k-1; tranNo >= 0; tranNo--) {
            if(tranNo%2 == 0) {
                cur[tranNo] = max(-prices[i] + ahead[tranNo+1], 0 + ahead[tranNo]);
            }
            else cur[tranNo] = max(prices[i] + ahead[tranNo+1], 0 + ahead[tranNo]);
        }
        ahead = cur;
    }

    return ahead[0];
}











int main() {

    vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};
    int n = prices.size();
    int k = 2;


// Soln-1 MEMORIZATION Approach
    cout << "Solve using MEMORIZATION Approach "<< endl;
    cout << "The maximum profit that can be generated is " << maximumProfit_1(prices, n, k) << endl << endl;



// Soln-2 TABULATION Approach
    cout << "Solve using TABULATION Approach "<< endl;
    cout << "The maximum profit that can be generated is " << maximumProfit_2(prices, n, k) << endl << endl;




// Soln-3 SPACE OPTIMISATION Approach
    cout << "Solve using SPACE OPTIMISATION Approach "<< endl;
    cout << "The maximum profit that can be generated is " << maximumProfit_3(prices, n, k) << endl << endl;



    return 0;
}
