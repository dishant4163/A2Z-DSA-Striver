// Target Sum


/*//Problem-Link->  https://www.naukri.com/code360/problems/target-sum_4127362

#include <bits/stdc++.h>

int helpSO(vector<int>& arr, int tar) {
    int n = arr.size();
    vector<int> prev(tar+1, 0), cur(tar+1, 0);

    // Base Case-1
    if(arr[0] == 0) prev[0] = 2; // 2 cases -pick and not pick
    else prev[0] = 1; // 1 case - not pick
    //Base Case-2
    if(arr[0] != 0 && arr[0] <= tar) prev[arr[0]] = 1; // 1 case -pick

    for(int ind = 1; ind < n; ind++) {
        for(int sum = 0; sum <= tar; sum++) {
            int notTake = prev[sum];
            int take = 0;
            if(arr[ind] <= sum) take = prev[sum - arr[ind]];

            cur[sum] = notTake + take;
        }
        prev = cur;
    }
    return prev[tar];
}

int targetSum(int n, int target, vector<int>& arr) {
    // Write your code here.
    int totSum = 0;
    for(int i = 0; i < n; i++) totSum += arr[i];

    if(totSum - target < 0) return 0;
    if((totSum-target)%2 == 1) return 0;

    int s2 = (totSum - target) / 2;
    return helpSO(arr, s2);
}


*/




#include<bits/stdc++.h>
using namespace std;


// Soln-1 MEMORIZATION Approach
int memoHelp(int ind, int tar, vector<int>& arr, vector<vector<int>>& dp) {
    //Base Case
    if(ind == 0) {
        if(tar == 0 && arr[0] == 0) return 2;
        if(tar == 0 || tar == arr[0]) return 1;
        return 0;
    }

    if(dp[ind][tar] != -1) return dp[ind][tar];

    int notTake = memoHelp(ind-1, tar, arr, dp);
    int take = 0;
    if(arr[ind] <= tar) take = memoHelp(ind-1, tar-arr[ind], arr, dp);

    return dp[ind][tar] = notTake + take;
}

int targetSum_1(int n, int target, vector<int>& arr) {
    int totSum = 0;
    for(int i = 0; i < n; i++) totSum += arr[i];

    if(totSum-target < 0) return 0;
    if((totSum - target)%2 == 1) return 0;

    int s2 = (totSum-target) / 2;

    vector<vector<int>> dp(n, vector<int>(s2+1, -1));
    return memoHelp(n-1, s2, arr, dp);
}





// Soln-2 TABULATION Approach
int tabHelp(vector<int>& arr, int tar) {
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(tar+1, 0));

    if(arr[0] == 0) dp[0][0] = 2;
    else dp[0][0] = 1;

    if(arr[0] != 0 && arr[0] <= tar) dp[0][arr[0]] = 1;

    for(int ind = 1; ind < n; ind++) {
        for(int sum = 0; sum <= tar; sum++) {
            int notTake = dp[ind-1][sum];
            int take = false;
            if(arr[ind] <= sum) take = dp[ind-1][sum - arr[ind]];

            dp[ind][sum] = notTake + take;
        }
    }
    return dp[n-1][tar];
}

int targetSum_2(int n, int target, vector<int>& arr) {
    int totSum = 0;
    for(int i = 0; i < n; i++) totSum += arr[i];

    if(totSum-target < 0) return 0;
    if((totSum - target)%2 == 1) return 0;

    int s2 = (totSum-target) / 2;

    return tabHelp(arr, s2);
}





// Soln-3 SPACE OPTIMISATION Approach
int helpSO(vector<int>& arr, int tar) {
    int n = arr.size();
    vector<int> prev(tar+1, 0), cur(tar+1, 0);

    if(arr[0] == 0) prev[0] = 2;
    else prev[0] = 1;

    if(arr[0] != 0 && arr[0] <= tar) prev[arr[0]] = 1;

    for(int ind = 1; ind < n; ind++) {
        for(int sum = 0; sum <= tar; sum++) {
            int notTake = prev[sum];
            int take = false;
            if(arr[ind] <= sum) take = prev[sum - arr[ind]];

            cur[sum] = notTake + take;
        }
        prev = cur;
    }
    return prev[tar];
}

int targetSum_3(int n, int target, vector<int>& arr) {
    int totSum = 0;
    for(int i = 0; i < n; i++) totSum += arr[i];

    if(totSum-target < 0) return 0;
    if((totSum - target)%2 == 1) return 0;

    int s2 = (totSum-target) / 2;

    return helpSO(arr, s2);
}









int main() {

    vector<int> arr = {1, 2, 3, 1};
    int target = 3;
    int n = arr.size();


// Soln-1 MEMORIZATION Approach
    cout << "Solve using MEMORIZATION Approach "<< endl;
    cout << "The number of ways found is: " << targetSum_1(n, target, arr) << endl << endl;


// Soln-2 TABULATION Approach
    cout << "Solve using TABULATION Approach "<< endl;
    cout << "The number of ways found is: " << targetSum_2(n, target, arr) << endl << endl;


// Soln-3 SPACE OPTIMISATION Approach
    cout << "Solve using SPACE OPTIMISATION Approach "<< endl;
    cout << "The number of ways found is: " << targetSum_3(n, target, arr) << endl << endl;



    return 0;
}
