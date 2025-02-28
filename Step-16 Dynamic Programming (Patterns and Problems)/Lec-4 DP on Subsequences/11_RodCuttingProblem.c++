// Rod Cutting Problem


/*//Problem-Link-> https://www.naukri.com/code360/problems/rod-cutting-problem_800284  

int cutRod(vector<int> &price, int n) {
	// Write your code here.
	vector<int> prev(n+1, 0);

	// Base Case
	for(int N = 0; N <= n; N++) prev[N] = N * price[0];

	for(int ind = 1; ind < n; ind++) {
		for(int N = 0; N <= n; N++) {
			int rodLen = ind + 1;
			int notTake = prev[N];
			int take = -1e9;
			if(rodLen <= N) take = price[ind] + prev[N - rodLen];

			prev[N] = max(notTake, take);
		}
	}
	return prev[n];
}


*/




#include<bits/stdc++.h>
using namespace std;


// Soln-1 MEMORIZATION Approach
int memoHelp(int ind, int N, vector<int> &price, vector<vector<int>>& dp) {
    //Base Case 
    if(ind == 0) {
        return N * price[0];
    }

    if(dp[ind][N] != -1) return dp[ind][N];

    int rodLen = ind + 1;
    int notTake = 0 + memoHelp(ind-1, N, price, dp);
    int take = -1e9;
    if(rodLen <= N) take = price[ind] + memoHelp(ind, N - rodLen, price, dp);

    return dp[ind][N] = max(notTake, take);
}

int cutRod_1(vector<int> &price, int n) {
    vector<vector<int>> dp(n, vector<int>(n+1, -1));

    return memoHelp(n-1, n, price, dp);
}





// Soln-2 TABULATION Approach
int cutRod_2(vector<int> &price, int n) {
    vector<vector<int>> dp(n, vector<int>(n+1, 0));

    // Base Case
    for(int N = 0; N <= n; N++) dp[0][N] = N * price[0];

    for(int ind = 1; ind < n; ind++) {
        for(int N = 0; N <= n; N++) {
            int rodLen = ind + 1;
            int notTake = dp[ind-1][N];
            int take = -1e9;
            if(rodLen <= N) take = price[ind] + dp[ind][N - rodLen];

            dp[ind][N] = max(notTake, take);
        }
    }
    return dp[n-1][n];
}





// Soln-3 SPACE OPTIMISATION Approach
// solving using single array for space optimization
int cutRod_3(vector<int> &price, int n) {
    vector<int> prev(n+1, 0);

    //Base case
    for(int N = 0; N <= n; N++) prev[N] = N * price[0];

    for(int ind = 1; ind < n; ind++) {
        for(int N = 0; N <= n; N++) {
            int rodLen = ind + 1;
            int notTake = prev[N];
            int take = - 1e9;
            if(rodLen <= N) take = price[ind] + prev[N - rodLen];

            prev[N] = max(notTake, take);
        }
    }

    return prev[n];
}









int main() {

    vector<int> price =  {1, 5, 8, 9, 10, 17, 17, 20};
    int n = price.size();


// Soln-1 MEMORIZATION Approach
    cout << "Solve using MEMORIZATION Approach "<< endl;
    cout << "The maximum cost obtained by cutting the rod & selling its pieces is: " << cutRod_1(price, n) << endl << endl;


// Soln-2 TABULATION Approach
    cout << "Solve using TABULATION Approach "<< endl;
    cout << "The maximum cost obtained by cutting the rod & selling its pieces is: " << cutRod_2(price, n) << endl << endl;


// Soln-3 SPACE OPTIMISATION Approach
    cout << "Solve using SPACE OPTIMISATION Approach "<< endl;
    cout << "The maximum cost obtained by cutting the rod & selling its pieces is: " << cutRod_3(price, n) << endl << endl;



    return 0;
}
