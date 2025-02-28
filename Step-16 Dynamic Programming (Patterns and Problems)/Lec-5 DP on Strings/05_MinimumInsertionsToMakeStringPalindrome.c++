// Minimum insertions to make string palindrome



/*// Problem-Link-> https://www.naukri.com/code360/problems/minimum-insertions-to-make-a-string-palindrome_985293

int lcs(string& s, string& t) {
	int n=s.size(), m=t.size();

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

int longestPalindromeSubsequence(string& s) {
	string t = s;
	reverse(s.begin(), s.end());
	return lcs(s, t);
}

int minimumInsertions(string &str){
	// Write your code here.
	return str.size() - longestPalindromeSubsequence(str);
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

int longestPalindromicSubsequenceTab(string& s) {
    string t = s;
    reverse(s.begin(), s.end());
    return lcsTab(s, t);
}

int minInsertion_1(string& str) {
    int n = str.size();

    return n - longestPalindromicSubsequenceTab(str);
}








// Soln-2 SPACE OPTIMISATION Approach
int lcs(string& s, string& t) {
    int n=s.size(), m = t.size();

    vector<int> prev(m+1, 0), cur(m+1, 0);

    for(int i=1; i <= n; i++) {
        for(int j=1; j <= m; j++) {
            if(s[i-1] == t[j-1]) {
                cur[j] = prev[j-1] + 1;
            }
            else cur[j] = max(prev[j], cur[j-1]);
        }
        prev = cur;
    }
    return prev[m];
}

int longestPalindromicSubsequence(string& s) {
    string t = s;
    reverse(s.begin(), s.end());
    return lcs(s, t);
}

int minInsertion_2(string& str) {
    int n = str.size();

    return n - longestPalindromicSubsequence(str);
}





int main() {

    string s = "abcaa";



// Soln-1 TABULATION Approach
    cout << "Solve using TABULATION Approach "<< endl;
    cout << "The Minimum insertions required to make string palindrome: " << minInsertion_1(s) << endl << endl;


// Soln-2 SPACE OPTIMISATION Approach
    cout << "Solve using SPACE OPTIMISATION Approach "<< endl;
    cout << "The Minimum insertions required to make string palindrome: " << minInsertion_2(s) << endl << endl;


    return 0;
}
