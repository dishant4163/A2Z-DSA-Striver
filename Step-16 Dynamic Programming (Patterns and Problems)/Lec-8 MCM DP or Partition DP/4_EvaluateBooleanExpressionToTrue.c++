// Evaluate Boolean Expression to True


/*// Problem-Link-> https://www.naukri.com/code360/problems/boolean-evaluation_1214650

#define ll long long
int mod = 1e9+7;


int evaluateExp(string & exp) {
    // Write your code here.
    int n = exp.size();

    vector<vector<vector<ll>>> dp(n+1, vector<vector<ll>>(n+1, vector<ll>(2, 0)));

    for(int i = n - 1; i >= 0; i--) {
        for(int j = 0; j < n; j++) {
             // Base case 1: i > j is an invalid case, so continue
            if(i > j) continue;;

            for(int isTrue = 0; isTrue <= 1; isTrue++) {
                // Base case 2: i == j, evaluate the single character
                if(i == j) {
                    if(isTrue) dp[i][j][isTrue] = exp[i] == 'T';
                    else dp[i][j][isTrue] = exp[i] == 'F';
                    continue;
                }

                // Recurrence logic:
                ll ways = 0;
                for(int ind = i+1; ind <= j-1; ind += 2) {
                    ll lT = dp[i][ind-1][1];
                    ll lF = dp[i][ind-1][0];
                    ll rT = dp[ind+1][j][1];
                    ll rF = dp[ind+1][j][0];

                    if(exp[ind] == '&') {
                        if(isTrue) ways += (lT*rT)%mod;
                        else ways += (lF*rT)%mod + (lT*rF)%mod + (lF*rF)%mod;
                    }
                    else if(exp[ind] == '|') {
                        if(isTrue) ways += (lF*rT)%mod + (lT*rF)%mod + (lT*rT)%mod;
                        else ways += (lF*rF)%mod;
                    }
                    else {
                        if(isTrue) ways += (lF*rT)%mod + (lT*rF)%mod;
                        else ways += (lT*rT)%mod + (lF*rF)%mod;
                    }
                }

                dp[i][j][isTrue] = ways % mod;
            }

        }
    }

    return dp[0][n-1][1];
}


*/



#include<bits/stdc++.h>
using namespace std;


#define ll long long
int mod = 1e9 + 7;


// Soln-1 RECURSION Approach
int solve(int i, int j, int isTrue, string& exp) {
    // Base case 1: If i > j, it's an invalid expression, return 0
    if(i > j) return 0;

    // Base case 2: If i and j are the same, evaluate the single character
    if(i == j) {
        if(isTrue == 1) return exp[i] == 'T' ? 1 : 0;
        else return exp[i] == 'F' ? 1 : 0;
    }

    ll ways = 0;

    // iterate through the expression
    for(int ind = i+1; ind <= j-1; ind += 2) {
        ll lT = solve(i, ind-1, 1, exp); //Number of ways to make the left expression true
        ll lF = solve(i, ind-1, 0, exp); //Number of ways to make the left expression false
        ll rT = solve(ind+1, j, 1, exp); //Number of ways to make the right expression true
        ll rF = solve(ind+1, j, 0, exp); //Number of ways to make the right expression false

        if(exp[ind] == '&') {
            if(isTrue) ways += (lT*rT)%mod;
            else ways += (lF*rT)%mod + (lT*rF)%mod + (lF*rF)%mod;
        }
        else if(exp[ind] == '|') {
            if(isTrue) ways += (lF*rT)%mod + (lT*rF)%mod + (lT*rT)%mod;
            else ways += (lF*rF)%mod;
        }
        else {
            if(isTrue) ways += (lF*rT)%mod + (lT*rF)%mod;
            else ways += (lT*rT)%mod + (lF*rF)%mod;
        }
    }

    return ways%mod;
}


int evaluateExp_1(string& exp) {
    int n = exp.size();

    return solve(0, n-1, 1, exp);
}








// Soln-2 MEMORIZATION Approach
int memo(int i, int j, int isTrue, string& exp, vector<vector<vector<ll>>>& dp) {
    // Base case 1: If i > j, it's an invalid expression, return 0
    if(i > j) return 0;

    // Base case 2: If i and j are the same, evaluate the single character
    if(i == j) {
        if(isTrue == 1) return exp[i] == 'T' ? 1 : 0;
        else return exp[i] == 'F' ? 1 : 0;
    }

    if(dp[i][j][isTrue] != -1) return dp[i][j][isTrue];

    ll ways = 0;

    for(int ind = i+1; ind <= j-1; ind += 2) {
        ll lT = memo(i, ind-1, 1, exp, dp);
        ll lF = memo(i, ind-1, 0, exp, dp);
        ll rT = memo(ind+1, j, 1, exp, dp);
        ll rF = memo(ind+1, j, 0, exp, dp);

        if(exp[ind] == '&') {
            if(isTrue) ways += (lT*rT)%mod;
            else ways += (lF*rT)%mod + (lT*rF)%mod + (lF*rF)%mod;
        }
        else if(exp[ind] == '|') {
            if(isTrue) ways += (lF*rT)%mod + (lT*rF)%mod + (lT*rT)%mod;
            else ways += (lF*rF)%mod;
        }
        else {
            if(isTrue) ways += (lF*rT)%mod + (lT*rF)%mod;
            else ways += (lT*rT)%mod + (lF*rF)%mod;
        }
    }

    return dp[i][j][isTrue] = ways%mod;
}


int evaluateExp_2(string& exp) {
    int n = exp.size();
    vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(n, vector<ll>(2, -1)));

    return memo(0, n-1, 1, exp, dp);
}









// Soln-3 TABULATION Approach
int evaluateExp_3(string& exp) {
    int n = exp.size();

    vector<vector<vector<ll>>> dp(n+1, vector<vector<ll>>(n+1, vector<ll>(2, 0)));

    for(int i = n - 1; i >= 0; i--) {
        for(int j = 0; j <= n - 1; j++) {
             // Base case 1: i > j is an invalid case, so continue
            if(i > j) continue;;

            for(int isTrue = 0; isTrue <= 1; isTrue++) {
                // Base case 2: i == j, evaluate the single character
                if(i == j) {
                    if(isTrue) dp[i][j][isTrue] = exp[i] == 'T';
                    else dp[i][j][isTrue] = exp[i] == 'F';
                    continue;
                }

                // Recurrence logic:
                ll ways = 0;
                for(int ind = i+1; ind <= j-1; ind += 2) {
                    ll lT = dp[i][ind-1][1];
                    ll lF = dp[i][ind-1][0];
                    ll rT = dp[ind+1][j][1];
                    ll rF = dp[ind+1][j][0];

                    if(exp[ind] == '&') {
                        if(isTrue) ways += (lT*rT)%mod;
                        else ways += (lF*rT)%mod + (lT*rF)%mod + (lF*rF)%mod;
                    }
                    else if(exp[ind] == '|') {
                        if(isTrue) ways += (lF*rT)%mod + (lT*rF)%mod + (lT*rT)%mod;
                        else ways += (lF*rF)%mod;
                    }
                    else {
                        if(isTrue) ways += (lF*rT)%mod + (lT*rF)%mod;
                        else ways += (lT*rT)%mod + (lF*rF)%mod;
                    }
                }

                dp[i][j][isTrue] = ways % mod;
            }

        }
    }

    return dp[0][n-1][1];
}








int main() {

    string exp = "F|T^F";


// Soln-1 RECURSION Approach
    cout << "Solve using RECURSION Approach " << endl;
    cout << "The total number of ways: " << evaluateExp_1(exp) << endl << endl;



// Soln-2 MEMORIZATION Approach
    cout << "Solve using MEMORIZATION Approach " << endl;
    cout << "The total number of ways: " << evaluateExp_2(exp) << endl << endl;



// Soln-3 TABULATION Approach
    cout << "Solve using TABULATION Approach " << endl;
    cout << "The total number of ways: " << evaluateExp_3(exp) << endl << endl;




    return 0;
}
