// Distinct Subsequences



/*//Problem-Link->  https://www.naukri.com/code360/problems/subsequence-counting_3755256


const int mod = 1e9 + 7;

// Solve using Sapce Optimization using SINGLE 1-D array
int distinctSubsequences(string &s, string &t) {
	// Write your code here.
	int n = s.size(), m = t.size();
	vector<int> prev(m+1, 0);
	//Base Case 
	prev[0] = 1;

	for(int i = 1; i <= n; i++) {
		for(int j = m; j >= 1; j--) {
			if(s[i-1] == t[j-1]) prev[j] = prev[j-1] + prev[j]; 
		}
	}

	return prev[m] % mod;
}

*/


#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;


// Soln-1 MEMORIZATION Approach
int memo(string& s, string& t, int ind1, int ind2, vector<vector<int>>& dp) {
    // Base Case
    if(ind2 < 0) return 1;
    if(ind1 < 0) return 0;

    if(dp[ind1][ind2] != -1) return dp[ind1][ind2];

    if(s[ind1] == t[ind2]) {
        int leaveOne = memo(s, t, ind1-1, ind2-1, dp);
        int stay = memo(s, t, ind1-1, ind2, dp);

        return dp[ind1][ind2] = (leaveOne + stay) % mod;
    }
    else return dp[ind1][ind2] = memo(s, t, ind1-1, ind2, dp);
}

int subsequenceCounting_1(string &s1, string &s2, int n, int m) {
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return memo(s1, s2, n-1, m-1, dp);
}






// Soln-2 TABULATION Approach
int subsequenceCounting_2(string &s1, string &s2, int n, int m) {
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    // Base Case
    for(int i=0; i <= n; i++) dp[i][0] = 1;
    for(int j = 1; j <= m; j++) dp[0][j] = 0; // note can ommit this bcz we 
    // initailize dp with 0 i.e, (m+1, 0)

    for(int i=1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(s1[i-1] == s2[j-1]) dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            else dp[i][j] = dp[i-1][j];
        }
    }

    return dp[n][m] % mod;
}





// Soln-3 SPACE OPTIMISATION Approach (using 2, 1-D array)
int subsequenceCounting_3(string &s, string &t, int n, int m) {
    vector<int> prev(m+1, 0), cur(m+1, 0);

    // Base Case
    prev[0] = cur[0] = 1;

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(s[i-1] == t[j-1]) cur[j] = prev[j-1] + prev[j];
            else cur[j] = prev[j];
        }
        prev = cur;
    }

    return prev[m] % mod;
}




// Soln-4 SPACE OPTIMISATION Approach (using SINGLE 1-D array)
int subsequenceCounting_4(string &s, string &t) {
    int n = s.size(), m = t.size();

    vector<int> prev(m+1, 0);
    //Base Case

    prev[0] = 1;

    for(int i = 1; i <= n; i++) {
        for(int j = m; j >= 1; j--) {
            if(s[i-1] == t[j-1]) 
                prev[j] = prev[j-1] + prev[j];
        }
    }

    return prev[m] % mod;
}





int main() {

    string s1 = "babgbag";
    string s2 = "bag";

// Soln-1 MEMORIZATION Approach
    cout << "Solve using MEMORIZATION Approach "<< endl;
    cout << "The Count of Distinct Subsequences is " << subsequenceCounting_1(s1, s2, s1.size(), s2.size()) << endl << endl;


// Soln-2 TABULATION Approach
    cout << "Solve using TABULATION Approach "<< endl;
    cout << "The Count of Distinct Subsequences is " << subsequenceCounting_2(s1, s2, s1.size(), s2.size()) << endl << endl;


// Soln-3 SPACE OPTIMISATION Approach (using 2, 1-D array)
    cout << "Solve using SPACE OPTIMISATION Approach using 2, 1-D arrays "<< endl;
    cout << "The Count of Distinct Subsequences is " << subsequenceCounting_3(s1, s2, s1.size(), s2.size()) << endl << endl;



// Soln-3 SPACE OPTIMISATION Approach (using 2, 1-D array)
    cout << "Solve using SPACE OPTIMISATION Approach using Single 1-D array"<< endl;
    cout << "The Count of Distinct Subsequences is " << subsequenceCounting_4(s1, s2) << endl << endl;



    return 0;
}
