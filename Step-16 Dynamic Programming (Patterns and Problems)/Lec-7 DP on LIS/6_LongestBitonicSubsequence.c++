// Longest Bitonic Subsequence


/*// Problem-Link->  https://www.naukri.com/code360/problems/longest-bitonic-sequence_1062688  

int longestBitonicSubsequence(vector<int>& arr, int n) {
	// Write your code here.
	vector<int> dp1(n, 1);
	vector<int> dp2(n, 1);

	for(int i=0; i < n; i++) {
		for(int prev = 0; prev < i; prev++) {
			if(arr[prev] < arr[i] && 1+dp1[prev] > dp1[i]) {
				dp1[i] = 1 + dp1[prev];
			}
		}
	}

	for(int i = n-1; i >= 0; i--) {
		for(int prev = n-1; prev > i; prev--) {
			if(arr[prev] < arr[i] && 1+dp2[prev] > dp2[i]) {
				dp2[i] = 1 + dp2[prev];
			}
		}
	}

	int ans = 0;
	for(int i = 0; i < n; i++) {
		ans = max(ans, dp1[i] + dp2[i] - 1);
	}

	return ans;
}


*/



#include <bits/stdc++.h>
using namespace std;



// Function to find the length of the longest bitonic subsequence
int longestBitonicSequence(vector<int>& arr, int n)  {
    vector<int> dp1(n, 1);
    vector<int> dp2(n, 1);

    // Calculate the Longest Increasing Subsequence
    for(int i = 0; i < n; i++) {
        for(int prev = 0; prev < i; prev++) {
            if(arr[prev] < arr[i] && dp1[prev] + 1 > dp1[i]) {
                dp1[i] = 1 + dp1[prev];
            }
        }
    }

    // Reverse the direction of nested loops to calculate 
    // the Longest Decreasing Subsequence
    for(int i = n-1; i >= 0; i--) {
        for(int prev = n-1; prev > i; prev--) {
            if(arr[prev] < arr[i] && dp2[prev] + 1 > dp2[i]) {
                dp2[i] = 1 + dp2[prev];
            }
        }
    }

    int maxLen = 0;
    for(int i = 0; i < n; i++) {
        // subtracting 1 bcz of common element present in both dp1 & dp2 
        // and count twice so subtract 1 from the total dp
        maxLen = max(maxLen, dp1[i] + dp2[i] - 1);
    }

    return maxLen;
}



int main() {
    vector<int> arr = {1, 11, 2, 10, 4, 5, 2, 1};
    int n = arr.size();

    cout << "The length of the longest bitonic subsequence is : " << longestBitonicSequence(arr, n) << endl;

    return 0;
}
