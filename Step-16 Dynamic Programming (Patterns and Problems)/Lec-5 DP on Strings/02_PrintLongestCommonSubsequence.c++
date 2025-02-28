// Print Longest Common Subsequence


/*//Problem-Link-> https://www.naukri.com/code360/problems/print-longest-common-subsequence_8416383 

string findLCS(int n, int m,string &s1, string &s2){
	// Write your code here.
	vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

	for(int i=0; i <= n; i++) dp[i][0] = 0;
	for(int j=0; j <= m; j++) dp[0][j] = 0;

	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			if(s1[i-1] == s2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
			else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}

	int len = dp[n][m];
	int index = len - 1;
	int i=n, j=m;
	string ans = "";
	for(int k=0; k < len; k++) ans += "$";

	while(i > 0 && j > 0) {
		if(s1[i-1] == s2[j-1]) {
			ans[index] = s1[i-1];
			index--;
			i--;
			j--;
		}
		else if (dp[i-1][j] > dp[i][j-1]) i--;
		else j--;
	}

	return ans;
}

*/




#include<bits/stdc++.h>
using namespace std;


// Soln-1 MEMORIZATION Approach
// string findLCS_1(string &str1, string &str2) {
//     //
// }



// Soln-2 TABULATION Approach
string findLCS_2(string &str1, string &str2) {
    int n = str1.size(), m = str2.size();

    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    for(int j=0; j <= m; j++) dp[0][j] = 0;
    for(int i=0; i <= n; i++) dp[i][0] = 0;

    for(int ind1 = 1; ind1 <= n; ind1++) {
        for(int ind2 = 1; ind2 <= m; ind2++) {
            if(str1[ind1-1] == str2[ind2-1]) dp[ind1][ind2] = 1 + dp[ind1-1][ind2-1];
            else dp[ind1][ind2] = max(dp[ind1-1][ind2], dp[ind1][ind2-1]);
        }
    }

    int len = dp[n][m];
    int i = n, j = m;

    string ans = "";
    int index = len - 1;

    for(int k = 1; k <= len; k++) {
        ans += "$"; // dummy string
    }

    while(i > 0 && j > 0) {
        if(str1[i - 1] == str2[j - 1]) {
            ans[index] = str1[i-1];
            index--;
            i--; j--;
        }
        else if(str1[i-1] > str2[j-1]) i--;
        else j--;
    }
    return ans;
}



// Soln-3 SPACE OPTIMISATION Approach
// string findLCS_3(string &s, string &t) {
//     //
// }





int main() {

    string a = "aggtab";
    string b = "gxtxayb";


// Soln-1 MEMORIZATION Approach
    // cout << "Solve using MEMORIZATION Approach "<< endl;
    // cout << "The output for printing Longest common subsequence is: " << findLCS_1(a, b) << endl << endl;


// Soln-2 TABULATION Approach
    cout << "Solve using TABULATION Approach "<< endl;
    cout << "The output for printing Longest common subsequence is: " << findLCS_2(a, b) << endl << endl;


// Soln-3 SPACE OPTIMISATION Approach
    // cout << "Solve using SPACE OPTIMISATION Approach "<< endl;
    // cout << "The output for printing Longest common subsequence is: " << findLCS_3(a, b) << endl << endl;



    return 0;
}

