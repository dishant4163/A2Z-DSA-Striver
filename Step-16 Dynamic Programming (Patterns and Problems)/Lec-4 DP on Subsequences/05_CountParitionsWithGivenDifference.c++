// Count Partitions with Given Difference



/*// Problem-Link-> https://www.naukri.com/code360/problems/partitions-with-given-difference_3751628 



int mod = 1e9 + 7;

int findWays(vector<int>& arr, int tar) {
    int n = arr.size();
    vector<int> prev(tar+1, 0), cur(tar+1, 0);

    if(arr[0] == 0) prev[0] = 2;
    else prev[0] = 1;

    if(arr[0] != 0 && arr[0] <= tar) prev[arr[0]] = 1;

    for(int ind = 1; ind < n; ind++) {
        for(int sum = 0; sum <= tar; sum++) {
            int notTake = prev[sum];
            int take = 0;
            if(arr[ind] <= sum) take = prev[sum - arr[ind]];

            cur[sum] = (take + notTake) % mod;
        }
        prev = cur;
    }
    return prev[tar];
}

int countPartitions(int n, int d, vector<int> &arr) {
    // Write your code here.
    int totalSum = 0;
    for(int i=0; i < n; i++) totalSum += arr[i];

    vector<int> prev(d+1, 0), cur(d+1, 0);

    if(totalSum-d < 0) return 0;
    if((totalSum-d)%2 == 1) return 0;

    int s2 = (totalSum-d)/2;
    return findWays(arr, s2);
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

int countPartitions1(int d, vector<int>& num) {
    int n = num.size(), totalSum = 0;

    for(int i=0; i < n; i++) totalSum += num[i];

    //Edge cases
    if(totalSum - d < 0) return 0;
    if((totalSum -d) % 2 == 1) return 0;

    int s2 = (totalSum - d) / 2; // subset 2

    vector<vector<int>> dp(n, vector<int>(s2 + 1, -1));
    return memoHelp(n-1, s2, num, dp);
}





// Soln-2 TABULATION Approach
int findWaysTab(vector<int>& arr, int tar) {
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(tar+1, 0));

    if(arr[0] == 0) dp[0][0] = 2;
    else dp[0][0] = 1;

    if(arr[0] != 0 && arr[0] <= tar) dp[0][arr[0]] = 1;

    for(int ind = 1; ind < n; ind++) {
        for(int sum = 0; sum <= tar; sum++) {
            int notTake = dp[ind-1][sum];
            int take = 0;
            if(arr[ind] <= sum) take = dp[ind-1][sum - arr[ind]];

            dp[ind][sum] = notTake + take;
        }
    }
    return dp[n-1][tar];
}

int countPartitions2(int d, vector<int>& num) {
    int n = num.size();
    int totalSum = 0;
    for(int i = 0; i < n; i++) totalSum += num[i];

    //edge cases
    if(totalSum - d < 0 || (totalSum - d)%2) return 0;

    int s2 = (totalSum - d) / 2;

    return findWaysTab(num, s2);
}





// Soln-3 SPACE OPTIMIZATION Approach
int findWaysSO(vector<int>& arr, int tar) {
    int n = arr.size();
    vector<int> prev(tar+1, 0), cur(tar+1, 0);

    // Base Cases-1
    if(arr[0] == 0) prev[0] = 2; // 2 cases -pick and not pick
    else prev[0] = 1; // 1 case - not pick

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

int countPartitions3(int d, vector<int>& num) {
    int n = num.size(), totalSum = 0;
    for(int i=0; i < n; i++) totalSum += num[i];

    if(totalSum - d  < 0) return 0;
    if((totalSum-d) % 2 == 1) return 0;

    int s2 = (totalSum-d) / 2;
    return findWaysSO(num, s2);
}



int main() {

    vector<int> arr = {5,2,6,4};
    int d=3;


// Soln-1 MEMORIZATION Approach
    cout << "Solve using MEMORIZATION Approach "<< endl;
    cout << "The number of subsets/partitions found are: " << countPartitions1(d, arr) << endl << endl;



// Soln-2 TABULATION Approach
    cout << "Solve using TABULATION Approach "<< endl;
    cout << "The number of subsets/partitions found are: " << countPartitions2(d, arr) << endl << endl;




// Soln-3 SPACE OPTIMIZATION Approach
    cout << "Solve using SPACE OPTIMIZATION Approach "<< endl;
    cout << "The number of subsets/partitions found are: " << countPartitions3(d, arr) << endl << endl;




    return 0;
}
