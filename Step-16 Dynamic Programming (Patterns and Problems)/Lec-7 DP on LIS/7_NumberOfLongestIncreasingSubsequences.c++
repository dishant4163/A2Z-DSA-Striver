// Number of Longest Increasing Subsequences


/*// Problem-Link->  https://www.naukri.com/code360/problems/number-of-longest-increasing-subsequence_3751627     

int findNumberOfLIS(vector<int> &arr) {
    // Write your code here.
    int n = arr.size();
    vector<int> dp(n, 1), cnt(n, 1);
    int maxi = 0;

    for(int i=0; i < n; i++) {
        for(int prev=0; prev < i; prev++) {
            if(arr[prev] < arr[i] && dp[prev]+1 > dp[i]) {
                dp[i] = 1+dp[prev];
                //inherit
                cnt[i] = cnt[prev];
            }
            else if(arr[prev] < arr[i] && dp[prev]+1 == dp[i]){
                // increase the count
                cnt[i] += cnt[prev];
            }
        }
        maxi = max(maxi, dp[i]);
    }

    int ans = 0;
    for(int i=0; i < n; i++) {
        if(dp[i] == maxi) {
            ans += cnt[i];
        }
    }

    return ans;
}


*/



#include <bits/stdc++.h>
using namespace std;

// Function to find the count of Longest Increasing Subsequences (LIS)
int findNumberOfLIS(vector<int>& arr) {
    int n = arr.size();

    vector<int> dp(n, 1), cnt(n, 1);
    int maxi = 0;

    for(int i=0; i < n; i++) {
        for(int prev = 0; prev < i; prev++) {
            if(arr[prev] < arr[i] && dp[prev]+1 > dp[i]) {
                dp[i] = 1 + dp[prev];
                // inherit the count from the prev
                cnt[i] = cnt[prev];
            }
            else if(arr[prev] < arr[i] && dp[prev]+1 == dp[i]) {
                // Increase the count
                cnt[i] += cnt[prev];
            }
        }

        maxi = max(maxi, dp[i]);
    }

    int numOfLis = 0;
    for(int i=0; i < n; i++) {
        if(dp[i] == maxi) {
            numOfLis += cnt[i];
        }
    }

    return numOfLis;
}



int main() {
    vector<int> arr = {1, 5, 4, 3, 2, 6, 7, 2};

    cout << "The count of Longest Increasing Subsequences (LIS) is " << findNumberOfLIS(arr) << endl;

    return 0;
}
