// Shortest Common Supersequence



/*//Problem-Link->  https://www.naukri.com/code360/problems/shortest-supersequence_4244493

#include <bits/stdc++.h> 
string shortestSupersequence(string a, string b){
	// Write your code here.
	int n = a.size(), m = b.size();
	vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

	for(int i=0; i <= n; i++) dp[i][0] = 0;
	for(int j=0; j <= m; j++) dp[0][j] = 0;

	for(int i=1; i <= n; i++) {
		for(int j=1; j <= m; j++) {
			if(a[i-1] == b[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
			else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}

	string ans = "";
	int i=n, j=m;
	while(i > 0 && j > 0) {
		if(a[i-1] == b[j-1]) {
			ans += a[i-1];
			i--; j--;
		}
		// upward movement
		else if(dp[i-1][j] > dp[i][j-1]) {
			ans += a[i-1];
			i--;
		}
		// diagonal movement
		else {
			ans += b[j-1];
			j--;
		}
	}

	// check for remaining element & add them 
	while(i > 0) {
		ans += a[i-1];
		i--;
	}
	while(j > 0) {
		ans += b[j-1];
		j--;
	}

	reverse(ans.begin(), ans.end());

	return ans;
}


*/


#include<bits/stdc++.h>
using namespace std;


// Soln-1 MEMORIZATION Approach
// string shortestSupersequence_1(string str1, string str2) {
//     //
// }



// Soln-2 TABULATION Approach
string shortestSupersequence_2(string &s, string &t) {
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

    int i=n, j=m;
    string ans = "";

    while(i > 0 && j > 0) {
        if(s[i-1] == t[j-1]) {
            ans += s[i-1];
            i--; j--;
        }
        // UPward Movement in DP table
        else if(dp[i-1][j] > dp[i][j-1]) {
            ans += s[i-1];
            i--;
        }
        // Diagonal Movement in DP table
        else {
            ans += t[j-1];
            j--;
        }
    }

    // check for remaining element for the both string
    while(i > 0) {
        ans += s[i-1];
        i--;
    }

    while(j > 0) {
        ans += t[j-1];
        j--;
    }

    reverse(ans.begin(), ans.end());

    return ans;
}



// Soln-3 SPACE OPTIMISATION Approach
// string shortestSupersequence_3(string str1, string str2) {
//     //
// }





int main() {

    string str1 = "brute";
    string str2 = "groot";

// Soln-1 MEMORIZATION Approach
    // cout << "Solve using MEMORIZATION Approach "<< endl;
    // cout << "The Longest Common Supersequence is "<< shortestSupersequence_1(str1, str2) << endl << endl;


// Soln-2 TABULATION Approach
    cout << "Solve using TABULATION Approach "<< endl;
    cout << "The Longest Common Supersequence is : "<< shortestSupersequence_2(str1, str2) << endl << endl;


// Soln-3 SPACE OPTIMISATION Approach
    // cout << "Solve using SPACE OPTIMISATION Approach "<< endl;
    // cout << "The Longest Common Supersequence is "<< shortestSupersequence_3(str1, str2) << endl << endl;


    return 0;
}
