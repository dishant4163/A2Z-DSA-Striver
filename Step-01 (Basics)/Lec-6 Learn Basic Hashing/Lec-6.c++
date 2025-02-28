// ## Basic of HASHING(simple means Pre-storing/compute & then Fetching)

// Link-> https://www.youtube.com/watch?v=KEs5UyBJ39g

/*// Coding Ninja (Highest/Lowest Frequency Elements)Link-> https://www.naukri.com/code360/problems/k-most-occurrent-numbers_625382

vector<int> getFrequencies(vector<int>& v) {
    // Write Your Code Here
    unordered_map<int, int> mpp;
    int n = v.size();

    for(int i=0; i < n; i++) {
        mpp[v[i]]++;
    }

    int maxFreq = 0, minFreq = INT_MAX;
    int maxFreqEle = 0, minFreqEle = 0;

    //Traverse through map to find the Elements
    for(auto it: mpp) {
        int cnt = it.second;//Value
        int element = it.first;//Key

        if (cnt > maxFreq || (cnt == maxFreq && element < maxFreqEle)) {
            maxFreq = cnt;
            maxFreqEle = element;
        }

        if (cnt < minFreq || (cnt == minFreq && element < minFreqEle)) {
            minFreq = cnt;
            minFreqEle = element;
        }
    }

    return {maxFreqEle, minFreqEle};
}
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{

    // Number Hashing
    /*// Problem-1 Count Element in HashArray

    //    Input:
    //    n1=5
    //    arr[n1] = 1 3 2 1 3
    //    q1=5
    //    hash[arr[i]] = 1 4 2 3 12

    //    Output:
    //    2
    //    0
    //    1
    //    2
    //    0


    // Optimized approach using Hashing
        int n1; // Enter no/size of array want to enter
        cin >> n1;
        int arr[n1];
        for (int i=0; i<n1; i++) {
            cin >> arr[i]; // enter the element of array acc to size of it
        }

        // precompute
        int hash[13] = {0};
        for (int i=0; i<n1; i++) {
            hash[arr[i]] += 1;
        }

        //Queries(q)
        int q1;
        cin >> q1;
        while(q1--) {
            int number;
            cin >> number;
            // Fetch
            cout << hash[number] << endl;
        }
    */

    // Character Hashing
    /*// Problem-2 In given string count the no of time character appears

    //    Input:-
    //    s = abcdabehf
    //    hash[s[i]] = 5
    //    a
    //    g
    //    h
    //    b
    //    c

    //    Output:-
    //    2
    //    0
    //    1
    //    2
    //    1

        string s;
        cin >> s;

        // precompute
        int hash[26] = {0};
        for (int i=0; i < s.size(); i++){
            hash[s[i] - 'a']++;
        }

        int q2;
        cin >> q2;
        while(q2--) {
            char c;
            cin >> c;
            // Fetching
            cout << hash[c - 'a'] << endl;
        }
    */

    // MAPS

    // Number Mapping
    /*// Problem-3 Count Element in MapArray using Maps

    //   Input:
    //   7
    //   1 2 3 1 3 2 12
    //   5
    //   1 2 3 4 12

    //   Output:
    //   2
    //   2
    //   2
    //   0
    //   1

        int n2;
        cin >> n2;
        int arrr[n2];
        for (int i=0; i<n2; i++) {
            cin >> arrr[i];
        }

        // Precompute
        map<int, int>  mpp;
        for (int i=0; i<n2; i++) {
            mpp[arrr[i]]++;
        }

        // iterate over the map:
        // for(auto it : mpp){ //sorting, bcz map stores in sort manner
        //        cout << it.first << "->" << it.second << endl;
        //    }


        // Aaking Queries(q3)
        int q3;
        cin >> q3;
        while(q3--) {
            int num;
            cin >> num;
            //Fetch
            cout << mpp[num] << endl;
        }
    */

    return 0;
}
