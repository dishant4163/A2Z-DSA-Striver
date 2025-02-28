// Best Time To Buy and Sell Stocks with Transaction Fees



/*// Problem-Link-> https://www.naukri.com/code360/problems/best-time-to-buy-and-sell-stock-with-transaction-fee_3118974

int maximumProfit(vector<int> &prices, int n, int fee) {
	// Write your code here.
	vector<int> cur(2, 0), ahead(2, 0);

	for(int index = n-1; index >= 0; index--) {
		for(int buy = 0; buy <= 1; buy++) {
			if(buy == 1) {
				cur[buy] = max(-prices[index] + ahead[0], 0 + ahead[1]);
			}
			else cur[buy] = max(prices[index] - fee + ahead[1], 0 + ahead[0]);
		}
		ahead = cur;
	}
	return ahead[1];
}


*/



#include<bits/stdc++.h>
using namespace std;



// Soln-1 MEMORIZATION Approach
int memo(int index, int buy, vector<int>& val, int n, int fee, vector<vector<int>>& dp) {
    // base case
    if(index == n) return 0;

    if(dp[index][buy] != -1) return dp[index][buy];

    if(buy == 1) {
        return dp[index][buy] = max(-val[index] + memo(index+1, 0, val, n, fee, dp), 
                                    0 + memo(index+1, 1, val, n, fee, dp));
    }
    else {
        return dp[index][buy] = max(val[index] - fee + memo(index+1, 1, val, n, fee, dp),
                                0 + memo(index+1, 0, val, n, fee, dp));
    }
}

int maximumProfit_1(vector<int>&prices, int n, int fee) {
    vector<vector<int>> dp(n, vector<int>(2, -1));
    return memo(0, 1, prices, n, fee, dp);
}






// Soln-2 TABULATION Approach
int maximumProfit_2(vector<int>&prices, int n, int fee) {
    vector<vector<int>> dp(n+1, vector<int>(2, 0));

    for(int index = n-1; index >= 0; index--) {
        for(int buy = 0; buy <= 1; buy++) {
            if(buy == 1) {
                dp[index][buy] = max(-prices[index] + dp[index+1][0], 0 + dp[index+1][1]);
            }
            else {
                dp[index][buy] = max(prices[index] - fee + dp[index+1][1], 0 + dp[index+1][0]);
            }
        }
    }

    return dp[0][1];
}



// Soln-3 SPACE OPTIMISATION Approach
int maximumProfit_3(vector<int>&prices, int n, int fee) {
    vector<int> cur(2, 0), ahead(2, 0);

    for(int index = n-1; index >= 0; index--) {
        for(int buy = 0; buy <= 1; buy++) {
            if(buy == 1) {
                cur[buy] = max(-prices[index] + ahead[0], 0 + ahead[1]);
            }
            else {
                cur[buy] = max(prices[index] - fee + ahead[1], 0 + ahead[0]);
            }
        }
        ahead = cur;
    }

    return ahead[1];
}





int main() {

    vector<int> prices = {1, 3, 2, 8, 4, 9};
    int n = prices.size();
    int fee = 2;


// Soln-1 MEMORIZATION Approach
    cout << "Solve using MEMORIZATION Approach "<< endl;
    cout << "The maximum profit that can be generated is " << maximumProfit_1(prices, n, fee) << endl << endl;



// Soln-2 TABULATION Approach
    cout << "Solve using TABULATION Approach "<< endl;
    cout << "The maximum profit that can be generated is " << maximumProfit_2(prices, n, fee) << endl << endl;




// Soln-3 SPACE OPTIMISATION Approach
    cout << "Solve using SPACE OPTIMISATION Approach "<< endl;
    cout << "The maximum profit that can be generated is " << maximumProfit_3(prices, n, fee) << endl << endl;


    return 0;
}
