// Palindrome Partitioning - II | Front Partition



/*// Problem-Link->   https://www.naukri.com/code360/problems/palindrome-partitioning-ll_873266 

bool isPalindrome(int i, int j, string& s) {
    while(i < j) {
        if(s[i] != s[j]) return false;
        i++; 
        j--;
    }
    return true;
}

int palindromePartitioning(string str) {
    // Write your code here
    int n = str.size();
    vector<int> dp(n+1, 0);
    dp[n] = 0;

    for(int i = n-1; i >= 0; i--) {
        int minCost = INT_MAX;
        for(int j = i; j < n; j++) {
            if(isPalindrome(i, j, str)) {
                int cost = 1 + dp[j+1];
                minCost = min(minCost, cost);
            }
            dp[i] = minCost;
        }
    }

    return dp[0] - 1; // Subtract 1 as it counts partitions, not cuts.
}


*/



#include<bits/stdc++.h>
using namespace std;


// Soln-1 RECURSION Approach
bool isPalindrome(int i, int j, string& s) {
    while(i < j) {
        if(s[i] != s[j]) return false;
        i++;
        j--;
    }
    return true;
}

int solve(int i, int n, string& str) {
    // Base Case
    if(i == n) return 0;

    int minCost = INT_MAX;

    for(int j = i; j < n; j++) {
        if(isPalindrome(i, j, str)) {
            int cost = 1 + solve(j+1, n, str);
            minCost = min(minCost, cost);
        }
    }

    return minCost;
}

int palindromePartitioning_1(string& str) {
    int n = str.size();

    // Calling the recursive function and subtracting 1 as it counts partitions, not cuts.
    return solve(0, n, str) - 1;
}







// Soln-2 MEMORIZATION Approach
int memo(int i, int n, string& str, vector<int>& dp) {
    // Base Case
    if(i==n) return 0;

    int minCost = INT_MAX;

    if(dp[i] != -1) return dp[i];

    for(int j = i; j < n; j++) {
        if(isPalindrome(i, j, str)) {
            int cost = 1 + memo(j+1, n, str, dp);
            minCost = min(minCost, cost);
        }
    }

    return dp[i] = minCost;
}

int palindromePartitioning_2(string& str) {
    int n = str.size();
    vector<int> dp(n, -1);

    // Calling the recursive function and subtracting 1 as it counts partitions, not cuts.
    return memo(0, n, str, dp) - 1;
}








// Soln-3 TABULATION Approach
int palindromePartitioning_3(string& str) {
    int n = str.size();

    vector<int> dp(n+1, 0);
    dp[n] = 0; //Base Case: Initialize the last element to 0

    // Loop through the string in reverse order(Bottom-Up)
    for(int i = n - 1; i >= 0; i--) {
        int minCost = INT_MAX;
        // Consider all possible substrings starting from the current index
        for(int j = i; j < n; j++) {
            if(isPalindrome(i, j, str)) {
                int cost = 1 + dp[j+1];
                minCost = min(minCost, cost);
            }
        }
        dp[i] = minCost;
    }

    return dp[0] - 1; // Subtract 1 as it counts partitions, not cuts.
}






int main() {

    string str = "BABABCBADCEDE"; 


// Soln-1 RECURSION Approach
    cout << "Solve using RECURSION Approach " << endl;
    cout << "The minimum number of partitions: " << palindromePartitioning_1(str) << endl << endl;



// Soln-2 MEMORIZATION Approach
    cout << "Solve using MEMORIZATION Approach " << endl;
    cout << "The minimum number of partitions: " << palindromePartitioning_2(str) << endl << endl;



// Soln-3 TABULATION Approach
    cout << "Solve using TABULATION Approach " << endl;
    cout << "The minimum number of partitions: " << palindromePartitioning_3(str) << endl << endl;





    return 0;
}
