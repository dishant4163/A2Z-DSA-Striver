// Longest Palindromic Subsequence



/*//Problem-Link->  https://www.naukri.com/code360/problems/longest-palindromic-subsequence_842787

#include <bits/stdc++.h> 

int lcs(string& s, string& t) {
    int n = s.size(), m = t.size();

    vector<int> prev(m+1, 0), cur(m+1, 0);

    for(int i=1; i <= n; i++) {
        for(int j=1; j <= m; j++) {
            if(s[i-1] == t[j-1]) {
                cur[j] = 1 + prev[j-1];
            }
            else cur[j] = max(prev[j], cur[j-1]);
        }
        prev = cur;
    }

    return prev[m];
}

int longestPalindromeSubsequence(string s){
    // Write your code here.
    string t = s;
    reverse(t.begin(), t.end());
    return lcs(s, t);
}

*/


#include<bits/stdc++.h>
using namespace std;



// Soln-1 TABULATION Approach
int lcsTab(string& s, string& t) {
    int n = s.size(), m = t.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    for(int i=0; i <= n; i++) dp[i][0] = 0;
    for(int j=0; j <= m; j++) dp[0][j] = 0;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(s[i-1] == t[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    return dp[n][m];
}

int longestPalindromeSubsequence_1(string &s) {
    string t = s;
    reverse(t.begin(), t.end());
    return lcsTab(s, t);
}



// Soln-2 SPACE OPTIMISATION Approach
int lcsSO(string& s, string& t) {
    int n = s.size(), m = t.size();

    vector<int> prev(m+1, 0), cur(m+1, 0);

    for(int i=1; i <= n; i++) {
        for(int j=1; j <= m; j++) {
            if(s[i-1] == t[j-1]) {
                cur[j] = 1 + prev[j-1];
            }
            else cur[j] = max(prev[j], cur[j-1]);
        }
        prev = cur;
    }

    return prev[m];
}

int longestPalindromeSubsequence_2(string &s) {
    string t = s;
    reverse(t.begin(), t.end());
    return lcsSO(s, t);
}





int main() {

    string s = "bbabcbcab";


// Soln-2 TABULATION Approach
    cout << "Solve using TABULATION Approach "<< endl;
    cout << "The Length of Longest Palindromic Subsequence is " << longestPalindromeSubsequence_1(s) << endl << endl;


// Soln-3 SPACE OPTIMISATION Approach
    cout << "Solve using SPACE OPTIMISATION Approach "<< endl;
    cout << "The Length of Longest Palindromic Subsequence is " << longestPalindromeSubsequence_2(s) << endl << endl;



    return 0;
}
