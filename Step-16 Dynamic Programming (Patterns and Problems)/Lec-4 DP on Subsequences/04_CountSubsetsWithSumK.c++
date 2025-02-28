// Count Subsets with Sum K (for +ve Integers)


/*// Problem-Link-> https://www.naukri.com/code360/problems/count-subsets-with-sum-k_3952532

// Striver Bhaiya Code 
const int MOD = 1e9 + 7;
// tabulation
int findWays(vector<int>& arr, int k) {
	// Write your code here.
	int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(k+1, 0));

    //Base Case-1
    if(arr[0] == 0) dp[0][0] = 2;
    else dp[0][0] = 1;

    //Base Case-2
    // it not should be arr[0] = 0
    if(arr[0] != 0 && arr[0] <= k) dp[0][arr[0]] = 1;

    for(int ind = 1; ind < n; ind++) {
        for(int sum = 0; sum <= k; sum++) {
            int notTake = dp[ind-1][sum];
            int take = 0;
            if(arr[ind] <= sum) take = dp[ind-1][sum - arr[ind]];

            dp[ind][sum] = (notTake + take)%MOD;
        }
    }

    return dp[n-1][k];
}

SO_Striver
int findWays(vector<int>& arr, int k) {
	// Write your code here.
	int n = arr.size();
	vector<int> prev(k+1, 0), cur(k+1, 0);

	//Base Case-1
    if(arr[0] == 0) prev[0] = 2;
    else prev[0] = 1;
    //Base Case-2
    // it not should barr[0] = 0
    if(arr[0] != 0 && arr[0] <= k) prev[arr[0]] = 1;

	for(int ind = 1; ind < n; ind++) {
		cur[0] = 1;
		for(int sum = 0; sum <= k; sum++) {
			int notTake = prev[sum];
			int take = 0;
			if(arr[ind] <= sum) take = prev[sum - arr[ind]];

			cur[sum] = (notTake + take) % MOD;
		}
		prev = cur;
	}
	return prev[k];
}





//Code Help
// const int MOD = 1e9 + 7;

// int countSubsetsSumK(int ind, int sum, vector<int>& ar, int n) {
// 	if(ind == n) {
// 		if(sum == 0) return 1;
// 		else return 0;
// 	}

// 	// Include the current element
// 	int Include = countSubsetsSumK(ind + 1, sum - ar[ind], ar, n);

// 	//Exclude the current element
// 	int Exclude = countSubsetsSumK(ind + 1, sum, ar, n);

// 	return (Include + Exclude) % MOD;
// }

// int findWays(vector<int>& arr, int k)
// {
// 	// Write your code here.
// 	return countSubsetsSumK(0, k, arr, arr.size());
// }

*/



#include<bits/stdc++.h>
using namespace std;


// Soln-1 MEMORIZATION Approach
int memoHelp(int ind, int sum, vector<int>& arr, vector<vector<int>>& dp) {
    //Base Case-
    if(ind == 0) {
        if(sum == 0 && arr[0] == 0) return 2;
        if(sum == 0 || sum == arr[0]) return 1;
        return 0;
    }

    if(dp[ind][sum] != -1) return dp[ind][sum];

    int notTake = memoHelp(ind-1, sum, arr, dp);
    int take = 0;
    if(arr[ind] <= sum) take = memoHelp(ind-1, sum-arr[ind], arr, dp);

    return dp[ind][sum] = take + notTake;
}

int findWays1(vector<int>& num, int k) {
    int n = num.size();
    vector<vector<int>> dp(n, vector<int>(k+1, -1));
    return memoHelp(n-1, k, num, dp);
}





// Soln-2 TABULATION Approach
int findWays2(vector<int>& num, int k) {
    int n = num.size();
    vector<vector<int>> dp(n, vector<int>(k+1, 0));

    //Base Case-1
    if(num[0] == 0) dp[0][0] = 2;
    else dp[0][0] = 1;

    //Base Case-2
    // it not should be num[0] = 0
    if(num[0] != 0 && num[0] <= k) dp[0][num[0]] = 1;

    for(int ind = 1; ind < n; ind++) {
        for(int sum = 0; sum <= k; sum++) {
            int notTake = dp[ind-1][sum];
            int take = 0;
            if(num[ind] <= sum) take = dp[ind-1][sum - num[ind]];

            dp[ind][sum] = notTake + take;
        }
    }

    return dp[n-1][k];
}





// Soln-3 SPACE OPTIMIZATION Approach
int findWays3(vector<int>& num, int k) {
    int n = num.size();
    vector<int> prev(k+1, 0), cur(k+1, 0);

    //Base Case-1
    if(num[0] == 0) prev[0] = 2;
    else prev[0] = 1;
    //Base Case-2
    // it not should be num[0] = 0
    if(num[0] != 0 && num[0] <= k) prev[num[0]] = 1;

    for (int ind = 1; ind < n; ind++) {
        for (int sum = 0; sum <= k; sum++) {
            int notTake = prev[sum];
            int take = 0;
            if (num[ind] <= sum) take = prev[sum - num[ind]];

            cur[sum] = take + notTake;
        }
        prev = cur;
    }

    return prev[k];
}






int main() {

    vector<int> arr = {0, 0, 1};
    int k = 1;


// Soln-1 MEMORIZATION Approach
    cout << "Solve using MEMORIZATION Approach "<< endl;
    cout << "The number of subsets found are: " << findWays1(arr, k) << endl << endl;



// Soln-2 TABULATION Approach
    cout << "Solve using TABULATION Approach "<< endl;
    cout << "The number of subsets found are " << findWays2(arr, k) << endl << endl;



// Soln-3 SPACE OPTIMIZATION Approach
    cout << "Solve using SPACE OPTIMIZATION Approach "<< endl;
    cout << "The number of subsets found are " << findWays3(arr, k) << endl << endl;




    return 0;
}
