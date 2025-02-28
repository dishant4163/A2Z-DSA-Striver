// Best Time to Buy and Sell Stock-iii



/*// Problem-Link->  https://www.naukri.com/code360/problems/best-time-to-buy-and-sell-stock-iii_1071012

int maxProfit(vector<int>& prices) {
    // Write your code here.
    int n = prices.size();

    vector<vector<int>> cur(2, vector<int>(3, 0)), ahead(2, vector<int>(3, 0));

    for(int index = n-1; index >= 0; index--) {
        for(int buy = 0; buy <= 1; buy++) {
            for(int cap = 1; cap <= 2; cap++) {
                if(buy==1) {
                    cur[buy][cap] = max(-prices[index] + ahead[0][cap], 0+ ahead[1][cap]);
                }
                else cur[buy][cap] = max(prices[index] + ahead[1][cap - 1], 0+ ahead[0][cap]);
            }
        }
        ahead = cur;
    }

    return ahead[1][2];
}

*/


#include<bits/stdc++.h>
using namespace std;



// Soln-1 MEMORIZATION Approach
int memo(int index, int buy, int cap, vector<int>& val, int n, vector<vector<vector<int>>>& dp) {
    // base case
    if(index == n || cap == 0) return 0;

    if(dp[index][buy][cap] != -1) return dp[index][buy][cap];

    if(buy == 1) {
        return dp[index][buy][cap] = max(-val[index] + memo(index+1, 0, cap, val, n, dp), 
                                        0 + memo(index+1, 1, cap, val, n, dp));
    }
    else {
        return dp[index][buy][cap] = max(val[index] + memo(index+1, 1, cap-1, val, n, dp),
                                        0 + memo(index+1, 0, cap, val, n, dp));
    }
}


int maxProfit_1(vector<int>&prices, int n) {
    vector<vector<vector<int>>> dp(n, vector<vector<int>> (2, vector<int>(3, -1)));
    return memo(0, 1, 2, prices, n, dp);
}



// Soln-2 TABULATION Approach
int maxProfit_2(vector<int>&prices, int n) {
    vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (2, vector<int>(3, 0)));

    // Note :- as practically we don't need to write Base cases as they all 
    // are ZERO, and while declaring DP array for tabulation we assigned 3D-dp array with 0.

    for(int index = n-1; index >= 0; index--) {
        for(int buy = 0; buy <= 1; buy++) {

            // BeCareFull for cap bcz cap start from 0 & goto 2 but we start
            // cap from 1 bcz in base case we already do that so we satrt from 1
            for(int cap = 1; cap <= 2; cap++) {  
                if(buy == 1) {
                    dp[index][buy][cap] = max(-prices[index] + dp[index+1][0][cap],
                                            0 + dp[index+1][1][cap]);
                }
                else {
                    dp[index][buy][cap] = max(prices[index] + dp[index+1][1][cap-1], 
                                                0 + dp[index+1][0][cap]);
                }
            }
        }
    }

    return dp[0][1][2];
}



// Soln-3 SPACE OPTIMISATION Approach
int maxProfit_3(vector<int>&prices, int n) {
    vector<vector<int>> cur(2, vector<int>(3, 0)), ahead(2, vector<int>(3, 0));

    for(int index = n-1; index >= 0; index--) {
        for(int buy = 0; buy <= 1; buy++) {
            for(int cap = 1; cap <= 2; cap++) {
                if(buy == 1) {
                    cur[buy][cap] = max(-prices[index] + ahead[0][cap], 0 + ahead[1][cap]);
                }
                else cur[buy][cap] = max(prices[index] + ahead[1][cap-1], 0 + ahead[0][cap]);
            }
        }
        ahead = cur;
    }

    return ahead[1][2];
}










int main() {

    vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};
    int n = prices.size();


// Soln-1 MEMORIZATION Approach
    cout << "Solve using MEMORIZATION Approach "<< endl;
    cout << "The maximum profit that can be generated is " << maxProfit_1(prices, n) << endl << endl;



// Soln-2 TABULATION Approach
    cout << "Solve using TABULATION Approach "<< endl;
    cout << "The maximum profit that can be generated is " << maxProfit_2(prices, n) << endl << endl;




// Soln-3 SPACE OPTIMISATION Approach
    cout << "Solve using SPACE OPTIMISATION Approach "<< endl;
    cout << "The maximum profit that can be generated is " << maxProfit_3(prices, n) << endl << endl;



    return 0;
}
