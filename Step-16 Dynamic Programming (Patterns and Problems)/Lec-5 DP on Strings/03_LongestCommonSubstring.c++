// Longest Common Substring



/*//Problem-Link->  https://www.naukri.com/code360/problems/longest-common-substring_1235207

int lcs(string &str1, string &str2){
    // Write your code here.
    int n = str1.size(), m = str2.size();

    vector<int> prev(m+1, 0), cur(m+1, 0);
    int ans = 0;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(str1[i-1] == str2[j-1]) {
                cur[j] = 1 + prev[j-1];
                ans = max(ans, cur[j]);
            }
            else cur[j] = 0;
        }
        prev = cur;
    }

    return ans;
}


*/



#include<bits/stdc++.h>
using namespace std;



// Soln-1 TABULATION Approach
int lcs_1(string &s, string &t) {
    int n = s.size(), m = t.size();

    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    for(int i=0; i <= n; i++) dp[i][0] = 0;
    for(int j=0; j <= m; j++) dp[0][j] = 0;

    int ans = 0;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(s[i-1] == t[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
                ans = max(ans, dp[i][j]);
            }
            else dp[i][j] = 0;
        }
    }

    return ans;
}



// Soln-2 SPACE OPTIMISATION Approach
int lcs_2(string &s, string &t) {
    int n = s.size(), m = t.size();

    vector<int> prev(m+1, 0), cur(m+1, 0);

    int ans = 0;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(s[i-1] == t[j-1]) {
                cur[j] = 1 + prev[j-1];
                ans = max(ans, cur[j]);
            }
            else cur[j] = 0;
        }
        prev = cur;
    }

    return ans;
}





int main() {

    string s1 = "abcjklp";
    string s2 = "acjkp";



// Soln-1 TABULATION Approach
    cout << "Solve using TABULATION Approach "<< endl;
    cout << "The Length of Longest Common Substring is " << lcs_1(s1, s2) << endl << endl;


// Soln-2 SPACE OPTIMISATION Approach
    cout << "Solve using SPACE OPTIMISATION Approach "<< endl;
    cout << "The Length of Longest Common Substring is " << lcs_2(s1, s2) << endl << endl;



    return 0;
}
