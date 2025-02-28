// Best Time to Buy and Sell Stock


/*// Problem-Link->  https://www.naukri.com/code360/problems/stocks-are-profitable_893405

int maximumProfit(vector<int> &prices){
    // Write your code here.
    int minPrice = INT_MAX;
    int n = prices.size();
    int maxPro = 0;

    for (int i=0; i<n; i++) {
        minPrice = min(minPrice, prices[i]);
        maxPro = max(maxPro, prices[i] - minPrice);
    }

    return maxPro;
}

*/



#include <bits/stdc++.h>
using namespace std;

int maximumProfit(vector<int> &prices) {
    int n = prices.size();
    int mini = prices[0];
    int maxProfit = 0;

    for(int i = 1; i < n; i++) {
        int curProfit = prices[i] - mini;
        maxProfit = max(maxProfit, curProfit);
        // update lowest price for tracking actual current profit
        mini = min(mini, prices[i]);
    }

    return maxProfit;
}


int main() {

    vector<int> Arr  ={7,1,5,3,6,4};

    cout<<"The maximum profit by selling the stock is : "<<maximumProfit(Arr);
}
