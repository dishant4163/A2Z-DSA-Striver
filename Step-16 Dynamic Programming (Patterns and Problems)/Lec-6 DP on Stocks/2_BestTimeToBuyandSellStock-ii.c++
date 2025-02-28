// Best Time to Buy Buy and Sell Stock - II


/*// Problem-Link->  https://www.naukri.com/code360/problems/selling-stock_630282

long getMaximumProfit(long *values, int n) {
    //Write your code here
    vector<long> ahead(2, 0), cur(2, 0);

    //Base case
    ahead[0] = ahead[1] = 0;

    for(int index = n-1; index >= 0; index--) {
        for(int buy = 0; buy <= 1; buy++) {
            long profit = 0;

            if(buy) {
                profit = max(-values[index] + ahead[0], 0 + ahead[1]);
            }
            else {
                profit = max(values[index] + ahead[1], 0 + ahead[0]);
            }

            cur[buy] = profit;
        }
        ahead = cur;
    }
    return ahead[1];
}

*/


#include<bits/stdc++.h>
using namespace std;



// Soln-1 MEMORIZATION Approach
long memo(int ind, int buy, long* arr, int n, vector<vector<long>>& dp) {
    if(ind == n) return 0;

    if(dp[ind][buy] != -1) return dp[ind][buy];

    long profit = 0;

    if(buy) { // We can buy Stock
        profit = max(-arr[ind] + memo(ind+1, 0, arr, n, dp),
    0 + memo(ind+1, 1, arr, n, dp));
    }
    else { // We can sell Stock
        profit = max(arr[ind] + memo(ind+1, 1, arr, n, dp),
    0 + memo(ind+1, 0, arr, n, dp));
    }

    return dp[ind][buy] = profit;
}

long getMaximumProfit_1(long *arr, int n) {
    vector<vector<long>> dp(n, vector<long>(2, -1));
    return memo(0, 1, arr, n, dp);
}






// Soln-2 TABULATION Approach
long getMaximumProfit_2(long *arr, int n) {
    vector<vector<long>> dp(n+1, vector<long>(2, 0));

    // base case
    dp[n][0] = dp[n][1] = 0;

    for(int index = n-1; index >= 0; index--) {
        for(int buy = 0; buy <= 1; buy++) {
            long profit = 0;
            if(buy) {
                profit = max(-arr[index] + dp[index+1][0], 0 + dp[index+1][1]);
            }
            else {
                profit = max(arr[index] + dp[index+1][1], 0 + dp[index+1][0]);
            }

            dp[index][buy] = profit;
        }
    }

    return dp[0][1];
}






// Soln-3 SPACE OPTIMISATION Approach
long getMaximumProfit_3(long *arr, int n) {
    vector<long> ahead(2, 0), cur(2, 0);

    // base case
    ahead[0] = cur[1] = 0;

    for(int index = n-1; index >= 0; index--) {
        for(int buy = 0; buy <= 1; buy++) {
            long profit = 0;
            if(buy) {
                profit = max(-arr[index] + ahead[0], 0 + ahead[1]);
            }
            else profit = max(arr[index] + ahead[1], 0 + ahead[0]);

            cur[buy] = profit;
        }
        ahead = cur;
    }

    return ahead[1];
}










// Soln-4 Solve using variables 
long getMaximumProfit(long *values, int n) {
    //Write your code here
    long aheadBuy, aheadNotBuy, curBuy, curNotBuy;

    //Base case
    aheadBuy = aheadNotBuy = 0;

    for(int index = n-1; index >= 0; index--) {
        curNotBuy = max(values[index] + aheadBuy, 0 + aheadNotBuy);
        curBuy = max(-values[index] + aheadNotBuy, 0 + aheadBuy);

        aheadBuy = curBuy;
        aheadNotBuy = curNotBuy;
    }

    return aheadBuy;
}






int main() {

    int n = 6;
    long Arr[n] = {7, 1, 5, 3, 6, 4};

// Soln-1 MEMORIZATION Approach
    cout << "Solve using MEMORIZATION Approach "<< endl;
    cout << "The maximum profit that can be generated is " << getMaximumProfit_1(Arr, n) << endl << endl;



// Soln-2 TABULATION Approach
    cout << "Solve using TABULATION Approach "<< endl;
    cout << "The maximum profit that can be generated is " << getMaximumProfit_2(Arr, n) << endl << endl;




// Soln-3 SPACE OPTIMISATION Approach
    cout << "Solve using SPACE OPTIMISATION Approach "<< endl;
    cout << "The maximum profit that can be generated is " << getMaximumProfit_3(Arr, n) << endl << endl;



// Soln-4 Solve using variables 
    cout << "Solve using SPACE OPTIMISATION Approach "<< endl;
    cout << "The maximum profit that can be generated is " << getMaximumProfit(Arr, n) << endl << endl;



    return 0;
}

