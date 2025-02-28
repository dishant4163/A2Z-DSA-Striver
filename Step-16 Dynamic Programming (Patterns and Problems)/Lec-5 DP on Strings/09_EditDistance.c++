// Edit Distance



/*//Problem-Link->  https://www.naukri.com/code360/problems/edit-distance_630420

int editDistance(string str1, string str2) {
    //write you code here
    int n = str1.size(), m = str2.size();

    vector<int> prev(m+1, 0), cur(m+1, 0);
    // base case
    for(int j = 0; j <= m; j++) prev[j] = j;

    for(int i = 1; i <= n; i++) {
        // update the cur[0]
        cur[0] = i;
        for(int j = 1; j <= m; j++) {
            if(str1[i-1] == str2[j-1]) cur[j] = prev[j-1];
            else {
                cur[j] = 1 + min(prev[j-1], min(cur[j-1], prev[j]));
            }
        }
        prev = cur;
    }

    return prev[m];
}

*/


#include<bits/stdc++.h>
using namespace std;


// Soln-1 MEMORIZATION Approach
int memo(string &s, string &t, int i, int j, vector<vector<int>>& dp) {
    // Base Case
    if(i < 0) return j+1;
    if(j < 0) return i+1;

    if(dp[i][j] != -1) return dp[i][j];

    if(s[i] == t[j]) {
        return dp[i][j] = 0 + memo(s, t, i-1, j-1, dp);
    }
    else {
        return dp[i][j] = 1 + min(memo(s,t, i-1, j-1, dp), min(memo(s,t,i-1, j, dp), memo(s,t, i, j-1, dp)));
    }
}

int editDistance_1(string &s, string &t) {
    int n = s.size(), m = t.size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return memo(s, t, n-1, m-1, dp);
}





// Soln-2 TABULATION Approach
int editDistance_2(string &s, string &t) {
    // 1- based indexing
    int n = s.size(), m = t.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    // Base Cases
    for(int i = 0; i <= n; i++) dp[i][0] = i;
    for(int j = 0; j <= m; j++) dp[0][j] = j;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(s[i-1] == t[j-1]) dp[i][j] = dp[i-1][j-1];
            else {
                dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
            }
        }
    }

    return dp[n][m];
}






// Soln-3 SPACE OPTIMISATION Approach (using 2, 1-D array)
int editDistance_3(string &s, string &t) {
    // NOTE:-
    // dp[i][j], dp[i-1][j-1] in terms of cur & prev
    // dp[i] means cur & dp[i-1] means prev

    int n = s.size(), m = t.size();

    vector<int> prev(m+1, 0), cur(m+1, 0);

    //Base case
    for(int j = 0; j <= m; j++) prev[j] = j;

    for(int i = 1; i <= n; i++) {
        // always UPdate the cur for any row 0th index guy is 'i'
        cur[0] = i;
        for(int j = 1; j <= m; j++) {
            if(s[i-1] == t[j-1]) cur[j] = prev[j-1];
            else {
                cur[j] = 1 + min(prev[j-1], min(prev[j], cur[j-1]));
            }
        }
        prev = cur;
    }

    return prev[m];
// NOte we cannot further optimized this bcz we depend on prev 
}







int main() {

    string s1 = "horse";
    string s2 = "ros";

// Soln-1 MEMORIZATION Approach
    cout << "Solve using MEMORIZATION Approach "<< endl;
    cout << "The minimum number of operations required is: " << editDistance_1(s1, s2) << endl << endl;


// Soln-2 TABULATION Approach
    cout << "Solve using TABULATION Approach "<< endl;
    cout << "The minimum number of operations required is: " << editDistance_2(s1, s2) << endl << endl;


// Soln-3 SPACE OPTIMISATION Approach
    cout << "Solve using SPACE OPTIMISATION Approach using 2, 1-D arrays "<< endl;
    cout << "The minimum number of operations required is: " << editDistance_3(s1, s2) << endl << endl;



    return 0;
}
