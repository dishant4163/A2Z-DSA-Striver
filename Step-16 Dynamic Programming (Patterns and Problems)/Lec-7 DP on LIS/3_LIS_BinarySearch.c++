// Longest Increasing Subsequence | Binary Search



/*// Problem-Link-> https://www.naukri.com/code360/problems/longest-increasing-subsequence_630459  


// using LiS Binary Search
int longestIncreasingSubsequence(int arr[], int n){
    // Write Your Code here
    int len = 1;
    vector<int> temp;
    temp.push_back(arr[0]);

    for(int i = 1; i < n; i++) {
        if(arr[i] > temp.back()) {
            temp.push_back(arr[i]);
            len++;
        }
        else {
            int index = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin();
            temp[index] = arr[i];
        }
    }

    return len;
}

*/


#include<bits/stdc++.h>
using namespace std;


// Soln-> LIS Binary Search
int lisBinarySearch(int arr[], int n) {
    int len = 1;
    vector<int> temp;
    temp.push_back(arr[0]);

    for(int i = 1; i < n; i++) {
        if(arr[i] > temp.back()) {
            temp.push_back(arr[i]);
            len++;
        }
        else {
            int index = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin();
            temp[index] = arr[i];
        }
    }

    return len;
}



int main() {

    int arr[] = {10, 9, 2, 5, 3, 7, 101, 18};
    int n = sizeof(arr) / sizeof(arr[0]);


// Soln-> LIS Binary Search
    cout << "Solve using LIS Binary Search Approach "<< endl;
    cout << "The length of the longest increasing subsequence is " << lisBinarySearch(arr, n) << endl << endl;



    return 0;
}

