// Longest String Chain


/*// Problem-Link-> https://www.naukri.com/code360/problems/longest-string-chain_3752111  

bool checkPossible(string& s, string& t) {
    if(s.size() != t.size()+1) return false;

    int first =0, second = 0;

    while(first < s.size()) {
        if(second < t.size() && s[first] == t[second]) {
            first++; second++;
        }
        else first++;
    }

    if(first == s.size() && second == t.size()) return true;
    else return false;
}

bool comp(string& s, string& t) {
    return s.size() < t.size();
}

int longestStrChain(vector<string> &arr){
    // Write your code here.
    int n = arr.size();
    int ans = 0;

    sort(arr.begin(), arr.end(), comp);

    vector<int> dp(n, 1);

    for(int i = 0; i < n; i++) {
        for(int prevInd = 0; prevInd < i; prevInd++) {
            if(checkPossible(arr[i], arr[prevInd]) && 1+dp[prevInd] > dp[i]) {
                dp[i] = 1 + dp[prevInd];
            }
        }

        if(dp[i] > ans) {
            ans = dp[i];
        }
    }

    return ans;
}





*/



#include<bits/stdc++.h>
using namespace std;


// Function to do length compare check of strings
bool comp(string& s, string& t) {
    return s.size() < t.size(); // in increasing order
}


// function to compare check for character matches for the given string
bool compareCheckPossible(string& s, string& t) {
    // s is greater & t is smaller
    if(s.size() != t.size()+1) return false;

    // declare pointers
    int first = 0, second = 0;

    while(first < s.size()) {
        if(second < t.size() && s[first] == t[second]) {
            first++;
            second++;
        }
        else {
            first++;
        }
    }

    if(first == s.size() && second == t.size()) return true;
    else return false;
}


int longestStrChain(vector<string>& arr) {
    int n = arr.size(), ans = 0;

    // Sort the string arr according to the length
    sort(arr.begin(), arr.end(), comp);

    vector<int> dp(n, 1);

    for(int index = 0; index < n; index++) {
        for(int prevInd = 0; prevInd < index; prevInd++) {
            if(compareCheckPossible(arr[index], arr[prevInd]) && dp[prevInd] + 1 > dp[index]) {
                dp[index] = dp[prevInd] + 1;
            }
        }

        if(dp[index] > ans) {
            ans = dp[index];
        }
    }

    return ans;
}


int main() {

    vector<string> words = {"a","b","ba","bca","bda","bdca"};
	
	cout<<" The length of the longest string chain is : "<<longestStrChain(words) << endl << endl;


    return 0;
}
