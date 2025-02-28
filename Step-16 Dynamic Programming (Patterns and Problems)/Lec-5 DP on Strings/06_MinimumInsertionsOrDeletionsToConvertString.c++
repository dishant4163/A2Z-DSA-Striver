// Minimum Insertions/Deletions to Convert String



/*//Problem-Link->  https://www.naukri.com/code360/problems/minimum-number-of-deletions-and-insertions_4244510

int lcs(string& s, string& t) {
    int n = s.size(), m = t.size();

    vector<int> prev(m+1, 0), cur(m+1, 0);

    for(int i=1; i <= n; i++){
        for(int j=1; j <= m; j++) {
            if(s[i-1] == t[j-1]) cur[j] = 1 + prev[j-1];
            else cur[j] = max(prev[j], cur[j-1]);
        }
        prev = cur;
    }
    return prev[m];
}

int canYouMake(string &s1, string &s2){
    // Write your code here.
    int n = s1.size(), m = s2.size();

    return n+m - 2*lcs(s1, s2);
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

    for(int i=1; i <= n; i++) {
        for(int j=1; j <= m; j++) {
            if(s[i-1] == t[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[n][m];
}

int canYouMake_1(string& str1, string& str2) {
    int n = str1.size(), m = str2.size();

    return  n + m - 2*lcsTab(str1, str2);
}





// Soln-2 SPACE OPTIMISATION Approach
int lcsSO(string& s, string& t) {
    int n = s.size(), m = t.size();

    vector<int> prev(m+1, 0), cur(m+1, 0);

    for(int i=1; i <= n; i++) {
        for(int j=1; j <= m; j++) {
            if(s[i-1] == t[j-1]) cur[j] = 1 + prev[j-1];
            else cur[j] = max(prev[j], cur[j-1]);
        }
        prev = cur;
    }

    return prev[m];
}

int canYouMake_2(string& str1, string& str2) {
    int n = str1.size(), m = str2.size();

    return n + m - 2*lcsSO(str1, str2);
}





int main() {

    string str1 = "abcd";
    string str2 = "anc";


// Soln-1 TABULATION Approach
    cout << "Solve using TABULATION Approach "<< endl;
    cout << "The Minimum operations required to convert str1 to str2: " << canYouMake_1(str1, str2) << endl << endl;


// Soln-2 SPACE OPTIMISATION Approach
    cout << "Solve using SPACE OPTIMISATION Approach "<< endl;
    cout << "The Minimum operations required to convert str1 to str2: " << canYouMake_2(str1, str2) << endl << endl;


    return 0;
}
