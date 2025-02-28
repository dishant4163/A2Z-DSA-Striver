// Best Time to Buy and Sell Stock with Cooldown 


/*// Problem-Link->  https://www.naukri.com/code360/problems/highway-billboards_3125969

int stockProfit(vector<int> &prices){
    // Write your code here.
    int n = prices.size();

    vector<vector<int>> dp(n+2, vector<int>(2, 0));

    for(int index = n-1; index >= 0; index--) {
        for(int buy = 0; buy <= 1; buy++) {
            if(buy == 1) {
                dp[index][buy] = max(-prices[index] + dp[index+1][0], 0 + dp[index+1][1]);
            }
            else {
                dp[index][buy] = max(prices[index] + dp[index+2][1], 0 + dp[index+1][0]);
            }
        }
    }

    return dp[0][1];
}



*/




#include<bits/stdc++.h>
using namespace std;



// Soln-1 MEMORIZATION Approach
int memo(int index, int buy, vector<int>& val, int n, vector<vector<int>>& dp) {
    //Base case
    if(index >= n) return 0;

    if(dp[index][buy] != -1) return dp[index][buy];

    if(buy == 1) { // buy stock
        return dp[index][buy] = max(-val[index] + memo(index+1, 0, val, n, dp), 0 + memo(index+1, 1, val, n, dp));
    }
    else { // sell stock
        return dp[index][buy] = max(val[index] + memo(index+2, 1, val, n, dp), 0 + memo(index+1, 0, val, n, dp));
    }
}

int stockProfit_1(vector<int>&prices) {
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(2, -1));

    return memo(0, 1, prices, n, dp);
}






// Soln-2 TABULATION Approach
int stockProfit_2(vector<int>&prices) {
    int n = prices.size();

    vector<vector<int>> dp(n+2, vector<int>(2, 0));

    for(int i = n-1; i >= 0; i--) {
        for(int buy = 0; buy <= 1; buy++) {
            if(buy == 1) {
                dp[i][buy] = max(-prices[i] + dp[i+1][0], 0 + dp[i+1][1]);
            }
            else {
                dp[i][buy] = max(prices[i] + dp[i+2][1], 0 + dp[i+1][0]);
            }
        }
    }

    return dp[0][1];
}






// Soln-3 SPACE OPTIMISATION Approach
int stockProfit_3(vector<int>&prices) {

// we don't go with SO soln bcz it requires 3 1-D arrays to solve which 
// is less intutive as compared to tabulation 

    int n = prices.size();

    vector<int> cur(2, 0), front1(2, 0), front2(2, 0);

    for(int i = n-1; i >= 0; i--) {
        for(int b = 0; b <= 1; b++) {
            if(b == 1) {
                cur[b] = max(-prices[i] + front1[0], 0 + front1[1]);
            }
            else {
                cur[b] = max(prices[i] + front2[1], 0 + front1[0]);
            }
        }
        front2 = front1;
        front1 = cur;
    }

    return cur[1];
}





int main() {

    vector<int> prices {4, 9, 0, 4, 10};

// Soln-1 MEMORIZATION Approach
    cout << "Solve using MEMORIZATION Approach "<< endl;
    cout << "The maximum profit that can be generated is " << stockProfit_1(prices) << endl << endl;



// Soln-2 TABULATION Approach
    cout << "Solve using TABULATION Approach "<< endl;
    cout << "The maximum profit that can be generated is " << stockProfit_2(prices) << endl << endl;




// Soln-3 SPACE OPTIMISATION Approach
    cout << "Solve using SPACE OPTIMISATION Approach "<< endl;
    cout << "The maximum profit that can be generated is " << stockProfit_3(prices) << endl << endl;


    return 0;
}
