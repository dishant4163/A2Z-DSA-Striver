// Printing Longest Increasing Subsequence


/* // Problem-Link->  https://www.naukri.com/code360/problems/printing-longest-increasing-subsequence_8360670

// Tabulation
vector<int> printingLongestIncreasingSubsequence(vector<int> arr, int n) {
	// Write your code here
	vector<int> dp(n, 1);
    vector<int> hash(n);

    for(int index = 0; index <= n-1; index++) {
        hash[index] = index; // // initializing hashArr with current index
        for(int prevIndex = 0; prevIndex <= index-1; prevIndex++) {
            if(arr[prevIndex] < arr[index] && 1+dp[prevIndex] > dp[index]) {
                dp[index] = 1 + dp[prevIndex];
                hash[index] = prevIndex; // Backtrack by storing previndex element 
            }
        }
    }

    int ans = -1, lastIndex = -1;
    for(int i = 0; i <= n-1; i++) {
        if(dp[i] > ans) {
            ans = dp[i];
            lastIndex = i;
        }
    }

    vector<int> temp;
    temp.push_back(arr[lastIndex]);

    while(hash[lastIndex] != lastIndex) {
        lastIndex = hash[lastIndex];
        temp.push_back(arr[lastIndex]);
    }

	reverse(temp.begin(), temp.end());

	return temp;
}


*/


#include<bits/stdc++.h>
using namespace std;


/*// Soln-1 MEMORIZATION Approach
int printingLIS_1(int arr[], int n) {
    //
}





// Soln-3 SPACE OPTIMISATION Approach
int printingLIS_3(int arr[], int n) {
    //
}
*/






// Soln-2 TABULATION Approach
int printingLIS_2(int arr[], int n) {
    vector<int> dp(n, 1);
    vector<int> hash(n);

    for(int index = 0; index <= n-1; index++) {
        hash[index] = index; // // initializing hashArr with current index
        for(int prevIndex = 0; prevIndex <= index-1; prevIndex++) {
            if(arr[prevIndex] < arr[index] && 1+dp[prevIndex] > dp[index]) {
                dp[index] = 1 + dp[prevIndex];
                hash[index] = prevIndex; // Backtrack by storing previndex element 
            }
        }
    }

    int ans = -1, lastIndex = -1;
    for(int i = 0; i <= n-1; i++) {
        if(dp[i] > ans) {
            ans = dp[i];
            lastIndex = i;
        }
    }

    vector<int> temp;
    temp.push_back(arr[lastIndex]);

    while(hash[lastIndex] != lastIndex) {
        lastIndex = hash[lastIndex];
        temp.push_back(arr[lastIndex]);
    }

    reverse(temp.begin(), temp.end());

    //printing the LIS 
    for(auto it : temp) {
        cout << it << " ";
    }
    cout << endl;

    return ans;
}




int main() {

    int arr[] = {10, 9, 2, 5, 3, 7, 101, 18};
    int n = sizeof(arr) / sizeof(arr[0]);

/*// Soln-1 MEMORIZATION Approach
    cout << "Solve using MEMORIZATION Approach "<< endl;
    cout << "The length of the longest increasing subsequence is " << printingLIS_1(arr, n) << endl << endl;


// Soln-3 SPACE OPTIMISATION Approach
    cout << "Solve using MEMORIZATION Approach "<< endl;
    cout << "The length of the longest increasing subsequence is " << printingLIS_3(arr, n) << endl << endl;
*/




// Soln-2 TABULATION Approach
cout << "Solve using MEMORIZATION Approach "<< endl;
cout << "The length of the longest increasing subsequence is " << printingLIS_2(arr, n) << endl << endl;



    return 0;
}

