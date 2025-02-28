// Minimum cost to cut the stick


/*// Problem-Link->  https://www.naukri.com/code360/problems/cost-to-cut-a-chocolate_3208460  


int cost(int n, int c, vector<int> &cuts){
    // Write your code here.
    cuts.push_back(n);
    cuts.insert(cuts.begin(), 0);
    sort(cuts.begin(), cuts.end());

    vector<vector<int>> dp(c+2, vector<int>(c+2, 0));

    for(int i = c; i >= 1; i--) {
        for(int j = 1; j <= c; j++) {
            if(i  > j) continue;

            int mini = 1e9;

            for(int ind = i; ind <= j; ind++) {
                int Cost = cuts[j+1] - cuts[i-1] + dp[i][ind-1] + dp[ind+1][j];

                mini = min(mini, Cost);
            }

            dp[i][j] = mini;
        }
    }
    return dp[1][c];
}

*/



#include<bits/stdc++.h>
using namespace std;


// Soln-1 RECURSION Approach
int solve(int i, int j, vector<int>& cuts) {
    // Base Case: If i is greater than j, there are no cuts to consider.
    if(i > j) return 0;

    int mini = 1e9;

    for(int ind = i; ind <= j; ind++) {
        int ans = cuts[j+1] - cuts[i-1] + solve(i, ind-1, cuts) + solve(ind+1, j, cuts);
        mini = min(mini, ans);
    }

    return mini;
}

int minimumCost_1(int n, int c, vector<int> &cuts) {
    // Modify the cuts array by adding 0 at the beginning and 'n' at the end.

    cuts.push_back(n);
    cuts.insert(cuts.begin(), 0);

    sort(cuts.begin(), cuts.end());
    return solve(1, c, cuts);
}








// Soln-2 MEMORIZATION Approach
int memo(int i, int j, vector<int>& cuts, vector<vector<int>>& dp) {
    if(i > j) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    int mini = INT_MAX;

    for(int ind = i; ind <= j; ind++) {
        int ans = cuts[j+1]-cuts[i-1] + memo(i, ind-1, cuts, dp) + memo(ind+1, j, cuts, dp);
        mini = min(mini, ans);
    }

    return dp[i][j] = mini;
}


int minimumCost_2(int n, int c, vector<int> &cuts) {
    // Modify the cuts array by adding 0 at the beginning and 'n' at the end.
    cuts.push_back(n);
    cuts.insert(cuts.begin(), 0);

    sort(cuts.begin(), cuts.end());
    vector<vector<int>> dp(c+1, vector<int>(c+1, -1));
    return memo(1, c, cuts, dp);
}






// Soln-3 TABULATION Approach
int minimumCost_3(int n, int c, vector<int> &cuts) {
    // Modify the cuts array by adding 0 at the beginning and 'n' at the end.
    cuts.push_back(n);
    cuts.insert(cuts.begin(), 0);
    sort(cuts.begin(), cuts.end());

    vector<vector<int>> dp(c+2, vector<int>(c+2, 0)); 

    for (int i = c; i >= 1; i--) {
        for(int j = 1; j <= c; j++) {
            if(i > j) continue; // base case

            int mini = INT_MAX;

            for(int ind = i; ind <= j; ind++) {
                int ans = cuts[j+1] - cuts[i-1] + dp[i][ind-1] + dp[ind+1][j];

                mini = min(ans, mini);
            }

            dp[i][j] = mini;
        }
    }

    return dp[1][c];
}








int main() {

    vector<int> cuts = {3, 5, 1, 4};
    int size = cuts.size();
    int n = 7;

// Soln-1 Recusrion Approach
    cout << "Solve using Recursion Approach "<< endl;
    cout << "The minimum cost incurred is: " << minimumCost_1(n, size, cuts) << endl << endl;



// Soln-2 MEMORIZATION Approach
    cout << "Solve using MEMORIZATION Approach "<< endl;
    cout << "The minimum cost incurred is: " << minimumCost_2(n, size, cuts) << endl << endl;



// Soln-3 TABULATION Approach
    cout << "Solve using TABULATION Approach "<< endl;
    cout << "The minimum cost incurred is: " << minimumCost_3(n, size, cuts) << endl << endl;





    return 0;
}
