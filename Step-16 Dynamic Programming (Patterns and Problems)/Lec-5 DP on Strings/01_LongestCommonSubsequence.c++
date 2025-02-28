// Longest Common Subsequence


/*//Problem-Link->  https://www.naukri.com/code360/problems/longest-common-subsequence_624879

#include<vector>

int lcs(string s, string t) {
	//Write your code here
	int n = s.size() , m = t.size();
	vector<int> prev(m+1, 0), cur(m+1, 0);

	for(int j = 0; j <= m; j++) prev[j] = 0;

	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			if(s[i - 1] == t[j - 1]) cur[j] = 1 + prev[j - 1];
			else cur[j] = max(prev[j], cur[j - 1]);
		}
		prev = cur;
	}
	return prev[m];
}

*/



#include<bits/stdc++.h>
using namespace std;


// Soln-1 MEMORIZATION Approach
int memoHelp(int i, int j, string& s, string& t, vector<vector<int>>& dp) {
    // Base Case
    if(i < 0 || j < 0) return 0;

    if(dp[i][j] != -1) return dp[i][j];

    if(s[i] == t[j]) return dp[i][j] = 1 + memoHelp(i-1, j-1, s, t, dp);
    else return dp[i][j] = max(memoHelp(i-1, j, s, t, dp), memoHelp(i, j-1, s, t, dp));
}

int lcs_1(string s1, string s2) {
    int n = s1.size(), m = s2.size();
    vector<vector<int>> dp(n, vector<int>(m, -1));

    return memoHelp(n-1, m-1, s1, s2, dp);
}






// Soln-2 TABULATION Approach
int lcs_2(string s1, string s2) {
    int n = s1.size(), m = s2.size();

    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    for(int j = 0; j <= m; j++) dp[0][j] = 0;
    for(int i = 0; i <= n; i++) dp[i][0] = 0;


    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(s1[i] == s2[j]) dp[i][j] = 1 + dp[i-1][j-1];
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    // Printing DP Tabulation
    // for(int i=0; i <= n; i++) {
    //     for(int j=0; j <= m; j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }


    return dp[n][m];
}



// Soln-3 SPACE OPTIMISATION Approach
int lcs_3(string s1, string s2) {
    int n = s1.size(), m = s2.size();

    vector<int> prev(m+1, 0), cur(m+1, 0);

    for(int j = 0; j <= m; j++) prev[j] = 0;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(s1[i - 1] == s2[j - 1]) cur[j] = 1 + prev[j - 1];
            else cur[j] = max(prev[j], cur[j - 1]);
        }
        prev = cur;
    }
    return prev[m];
}





int main() {

    string s1 = "acd";
    string s2 = "ced";


// Soln-1 MEMORIZATION Approach
    cout << "Solve using MEMORIZATION Approach "<< endl;
    cout << "The Length of Longest Common Subsequence is " << lcs_1(s1, s2) << endl << endl;



// Soln-2 TABULATION Approach
    cout << "Solve using TABULATION Approach "<< endl;
    cout << "The Length of Longest Common Subsequence is " << lcs_2(s1, s2) << endl << endl;



// Soln-3 SPACE OPTIMISATION Approach
    cout << "Solve using SPACE OPTIMISATION Approach "<< endl;
    cout << "The Length of Longest Common Subsequence is " << lcs_3(s1, s2) << endl << endl;



    return 0;
}

