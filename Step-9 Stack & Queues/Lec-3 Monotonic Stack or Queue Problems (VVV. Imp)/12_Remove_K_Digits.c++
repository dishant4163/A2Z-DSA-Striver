// Remove K Digits



/* Remove K Digits_Coding Ninjas -> (  https://shorturl.at/HOF3e  )

string removeKDigits(string num, int k) {
    // Write your code here.
    int n = num.length();
    if(k >= n) return "0";

    stack<int> st;

    for(int i=0; i < n; i++) {
        while(!st.empty() && k > 0 && (st.top() - '0') > (num[i] - '0')) {
            st.pop();
            k--;
        }
        st.push(num[i]); //add string num i-th element
    }

    while(k > 0 && !st.empty()) {
        st.pop();
        k--;
    }

    if(st.empty()) return "0";

    string ans = "";
    while(!st.empty()) {
        ans += st.top();
        st.pop();
    }

    while(ans.size() != 0 && ans.back() == '0') ans.pop_back();

    reverse(ans.begin(), ans.end());

    return ans.empty() ? "0" : ans;
}


*/



#include<bits/stdc++.h>
using namespace std;


string remove_K_Digits(string s, int k) {
    int n = s.length();
    //If k is >= to the number of digits, return "0"
    if(k >= n) return "0";

    stack<int> st;

    for(int i=0; i < n; i++) {
        // While we can remove digits and the stack is not empty
        // and the current digit is less than the digit on top of the stack
        while(!st.empty() && k > 0 && (st.top() - '0') > (s[i] - '0')) {
            st.pop();
            k--;
        }
        st.push(s[i]);
    }

    // if we still have left-over to remove
    while(k > 0 && !st.empty()) {
        st.pop();
        k--;
    }

    if(st.empty()) return "0";

    //Build stack have some element
    string ans ="";
    while(!st.empty()) {
        ans += st.top();
        st.pop();
    }


//Edge Case, if zeros are at start and back of number
    while(ans.size() != 0 && ans.back() == '0') ans.pop_back();

// Reverse the result since we constructed it from the top of the stack
reverse(ans.begin(), ans.end());

    // Return "0" if the result is empty
    return ans.empty() ? "0" : ans;

}




int main() {

    string numStr = "1432219"; // input
    int k = 3; // Number of digits to remove

    string result = remove_K_Digits(numStr, k);
    cout << "Result after removing " << k << " digits: " << result << endl; // Expected output: "1219"


    /*// You can add more test cases here
    cout << endl;

    vector<pair<string, int>> testCases = {
        {"10200", 1},
        {"10", 2},
        {"100", 1},
        {"987654321", 4}
    };

    for (const auto& test : testCases) {
        string num = test.first;
        int removeCount = test.second;
        cout << "Original number: " << num << ", Remove " << removeCount << " digits: " 
            << remove_K_Digits(num, removeCount) << endl;
    }

*/



    return 0;
}

