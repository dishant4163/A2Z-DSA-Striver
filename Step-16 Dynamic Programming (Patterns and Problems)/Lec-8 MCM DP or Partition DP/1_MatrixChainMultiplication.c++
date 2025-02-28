// Matrix Chain Multiplication


/*// Problem-Link-> https://www.naukri.com/code360/problems/matrix-chain-multiplication_975344      

int matrixMultiplication(vector<int> &arr, int N) {
    // Write your code here.
    vector<vector<int>> dp(N, vector<int>(N, 0));

    // base case : dp[i][i] = 0; is done while declaring dp array which initialize with 0

    for(int i = N-1; i >= 1; i--) {
        for(int j = i+1; j < N; j++) {
            int mini = 1e9;

            for(int k = i; k < j; k++) {
                int steps = arr[i-1]*arr[k]*arr[j] + dp[i][k] + dp[k+1][j];

                mini = min(mini, steps);
            }

            dp[i][j] = mini;
        }
    }

    return dp[1][N-1];
}


*/



#include <bits/stdc++.h>
using namespace std;

// Soln-1 RECURSION Approach (gives TLE)
int solve(int i, int j, vector<int>& arr) {
    //base case
    if(i == j) return 0;

    int mini = 1e9;

    // partitioning loop from [k=i -> (j-1)]
    for(int k=i; k < j; k++) {
        int steps = arr[i-1]*arr[k]*arr[j] + solve(i, k, arr) + solve(k+1, j, arr);

        mini = min(mini, steps);
    }

    return mini;
}
int matrixMultiplication_1(vector<int>& arr, int N) {
    int i = 1, j = N-1;
    return solve(i, j, arr);
}





// Soln-2 MEMORIZATION Approach
int memo(int i, int j, vector<int>& arr, vector<vector<int>>& dp) {
    // Base Case
    if(i == j) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    int mini = 1e9;

    // partitioning loop from [k=i -> (j-1)]
    for(int k=i; k < j; k++) {
        int steps = arr[i-1]*arr[k]*arr[j] + memo(i, k, arr, dp) + memo(k+1, j, arr, dp);

        mini = min(mini, steps);
    }

    return dp[i][j] = mini;
}

int matrixMultiplication_2(vector<int>& arr, int N) {
    vector<vector<int>> dp(N, vector<int>(N, -1));

    return memo(1, N-1, arr, dp);
}





// Soln-3 TABULATION Approach
int matrixMultiplication_3(vector<int>& arr, int N) {
    vector<vector<int>> dp(N, vector<int>(N, 0));

    // Base case : dp[i][i] = 0; is done while declaring dp array 
    //which initialize with 0 OR we declare base using for loop for every i of dp[i][i] = 0;


    //for(int i=1; i < N; i++) dp[i][i] = 0;// Base case

    for(int i = N-1; i >= 1; i--) {
        for(int j = i+1; j < N; j++) {
            int mini = 1e9;

            for(int k = i; k < j; k++) {
                int steps = arr[i-1]*arr[k]*arr[j] + dp[i][k] + dp[k+1][j];

                mini = min(steps, mini);
            }

            dp[i][j] = mini;
        }
    }

    return dp[1][N-1];
}











int main() {

	vector<int> arr = {10, 20, 30, 40, 50};
	int n = arr.size();



// Soln-1 Recusrion Approach
    cout << "Solve using Recursion Approach "<< endl;
    cout << "The minimum number of operations is : " << matrixMultiplication_1(arr,n) << endl << endl;



// Soln-2 MEMORIZATION Approach
    cout << "Solve using MEMORIZATION Approach "<< endl;
    cout << "The minimum number of operations is : " << matrixMultiplication_2(arr,n) << endl << endl;



// Soln-3 TABULATION Approach
    cout << "Solve using TABULATION Approach "<< endl;
    cout << "The minimum number of operations is : " << matrixMultiplication_3(arr,n) << endl << endl;



	return 0;
}
