// Longest Divisible Subset


/*//Problem-Link->  https://www.naukri.com/code360/problems/divisible-set_3754960 


// Solve using LiS + Printing LiS
vector<int> divisibleSet(vector<int> &arr) {
    // Write your code here.
    int n = arr.size();
    sort(arr.begin(), arr.end());

    vector<int> dp(n, 1), hash(n), ans;

    for(int i = 0; i < n; i++) {
        hash[i] = i;
        for(int prev = 0; prev < i; prev++) {
            if(arr[i] % arr[prev] == 0 && 1 + dp[prev] > dp[i]) {
                dp[i] = 1 + dp[prev];
                hash[i] = prev;
            }
        }
    }

    int maxi = 0, lastIndex = 0;
    for(int i = 0; i < n; i++) {
        if(dp[i] > maxi) {
            maxi = dp[i];
            lastIndex = i;
        }
    }

    ans.push_back(arr[lastIndex]);

    while(hash[lastIndex] != lastIndex) {
        lastIndex = hash[lastIndex];
        ans.push_back(arr[lastIndex]);
    }

    reverse(ans.begin(), ans.end());

    return ans;
}

*/


#include<bits/stdc++.h>
using namespace std;


// Function to find the longest divisible subset
vector<int> divisibleSet(vector<int>& arr) {
    int n = arr.size();

    sort(arr.begin(), arr.end());

    vector<int> dp(n, 1), hash(n), ans;

    for(int i = 0; i < n; i++) {
        hash[i] = i;
        for(int prev = 0; prev < i; prev++) {
            if(arr[i] % arr[prev] == 0 && 1 + dp[prev] > dp[i]) {
                dp[i] = 1 + dp[prev];
                hash[i] = prev;
            }
        }
    }

    int maxi = 0, lastIndex = 0;
    for(int i = 0; i < n; i++) {
        if(dp[i] > maxi) {
            maxi = dp[i];
            lastIndex = i;
        }
    }

    ans.push_back(arr[lastIndex]);

    while(hash[lastIndex] != lastIndex) {
        lastIndex = hash[lastIndex];
        ans.push_back(arr[lastIndex]);
    }

    reverse(ans.begin(), ans.end());

    return ans;
}



int main() {
    vector<int> arr = {1, 16, 7, 8, 4};

    vector<int> ans = divisibleSet(arr);

    cout << "The longest divisible subset elements are: ";

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }

    return 0;
}
