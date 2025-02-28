// Wildcard Matching


/* // Problem-Link->  https://www.naukri.com/code360/problems/wildcard-pattern-matching_701650

#include<vector>
// Space Optimization
bool isAllStarsSo(string& p, int i) {
   for(int j = 1; j <= i; j++) {
      if(p[j-1] != '*') return false;
   }
   return true;
}

bool wildcardMatching(string pattern, string text) {
   // Write your code here.
   int n = pattern.size(), m = text.size();
   vector<bool> prev(m+1, false), cur(m+1, false);

   prev[0] = true;

   for(int j = 1; j <= m; j++) prev[j] = false;

   for(int i = 1; i <= n; i++) {
      cur[0] = isAllStarsSo(pattern, i);
      for(int j = 1; j <= m; j++) {
         if(pattern[i-1] == text[j-1] || pattern[i-1] == '?') {
            cur[j] = prev[j-1];
         }
         else if(pattern[i-1] == '*') cur[j] = prev[j] || cur[j-1];
         else cur[j] = false;
      }
      prev = cur;
   }

   return prev[m];
}

*/



#include<bits/stdc++.h>
using namespace std;



// Soln-1 MEMORIZATION Approach
bool memo(string &p, string &t, int i, int j, vector<vector<int>>& dp) {
    //Base Case-1 (both strings exhausted)
    if(i < 0 && j < 0) return true;

    //Base Case-2 (only pattern string exhausted but text string still left with elements)
    if(i < 0 && j >= 0) return false;

    //Base Case-3 (text string exhausted but pattern still have elements or '*' left behind)
    if(i >= 0 && j < 0) {
        for(int k = 0; k <= i; k++) {
            if(p[k] != '*') return false;
        }
        return true;
    }

    if(dp[i][j] != -1) return dp[i][j];

    if(p[i] == t[j] || p[i] == '?') {
        return dp[i][j] = memo(p, t, i-1, j-1, dp);
    }
    else if(p[i] == '*') {
        return dp[i][j] = memo(p,t, i-1, j, dp) || memo(p,t, i, j-1, dp);
    }
    else return dp[i][j] = false;
}

bool wildcardMatching_1(string &pattern, string &text) {
    int n =  pattern.size(), m = text.size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return memo(pattern, text, n-1, m-1, dp);
}






// Soln-2 TABULATION Approach
// Function to check if a substring of S1 contains only '*'
bool isAllStarsTab(string& p, int i) {
    // 1 based indexing
    for(int j = 1; j <= i; j++) {
        if(p[j-1] != '*') return false;
    }
    return true;
}


bool wildcardMatching_2(string &pattern, string &text) {
    // 1 based indexing
    int n = pattern.size(), m = text.size();
    vector<vector<bool>> dp(n+1, vector<bool>(m+1, false));

    //Base Case-1 (both strings exhausted)
    dp[0][0] = true;

    //Base Case-2 (only pattern string exhausted but text string still left with elements)
    for(int j = 1; j <= m; j++) dp[0][j] = false;

    //Base Case-3 (text string exhausted but pattern still have elements or '*' left behind)
    for(int i = 1; i <= n; i++) dp[i][0] = isAllStarsTab(pattern, i);


    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(pattern[i-1] == text[j-1] || pattern[i-1] == '?') {
                dp[i][j] = dp[i-1][j-1];
            }
            else if(pattern[i-1] == '*') dp[i][j] = dp[i-1][j] || dp[i][j-1];
            else dp[i][j] = false;
        }
    }

    return dp[n][m];
}








// Soln-3 SPACE OPTIMISATION Approach
bool isAllStarsSO(string& p, int i) {
    // for every row we are assigning the 0th column's value
    for(int j = 1; j <= i; j++) {
        if(p[j-1] != '*') return false;
    }
    return true;
}

bool wildcardMatching_3(string &pattern, string &text) {
    int n = pattern.size(), m = text.size();
    vector<bool> prev(m+1, false), cur(m+1, false);

    //Base Case-1 (both strings exhausted)
    prev[0] = true;

    //Base Case-2 (only pattern string exhausted but text string still left with elements)
    for(int j = 1; j <= m; j++) prev[j] = false;

    for(int i = 1; i <= n; i++) {
        // cur is the current row/s column and that cur's 0th
        // row has to assigned everytime
        cur[0] = isAllStarsSO(pattern, i);
        for(int j = 1; j <= m; j++) {
            if(pattern[i-1] == text[j-1] || pattern[i-1] == '?') {
                cur[j] = prev[j-1];
            }
            else if(pattern[i-1] == '*') {
                cur[j] = prev[j] || cur[j-1];
            }
            else cur[j] = false;
        }
        prev = cur;
    }

    return prev[m];
}





int main() {

    string s1 = "ab*cd";
    string s2 = "abdefcd";

// Soln-1 MEMORIZATION Approach
    cout << "Solve using MEMORIZATION Approach "<< endl;
    if (wildcardMatching_1(s1, s2)) 
        cout << "String S1 and S2 do match";
    else 
        cout << "String S1 and S2 do NOT match";
    cout << endl << endl;



// Soln-2 TABULATION Approach
    cout << "Solve using TABULATION Approach "<< endl;
    if (wildcardMatching_2(s1, s2)) 
        cout << "String S1 and S2 do match";
    else 
        cout << "String S1 and S2 do NOT match";
    cout << endl << endl;



// Soln-3 SPACE OPTIMISATION Approach
    cout << "Solve using SPACE OPTIMISATION Approach "<< endl;
    if (wildcardMatching_3(s1, s2)) 
        cout << "String S1 and S2 do match";
    else 
        cout << "String S1 and S2 do NOT match";
    cout << endl << endl;

    return 0;
}
