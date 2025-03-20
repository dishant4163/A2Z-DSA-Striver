// Word Ladder-ii



#include<bits/stdc++.h>
using namespace std;



// Solution ONLY for GFG(on leetcode could give TLE)
// TC:- O(N * word.length * 26) but for this code TC vary on example to example 
vector<vector<string>> findSequences(string beginWord, string endWord, vector<string> &wordList) {
    unordered_set<string> st(wordList.begin(), wordList.end());
    queue<vector<string>> q; // queue for storing list of string
    q.push({beginWord});
    vector<string> usedOnLevel; // for evry level how many strings are used
    usedOnLevel.push_back(beginWord);
    int level = 0;
    vector<vector<string>> ans;

    while(!q.empty()) {
        vector<string> sequenceVector = q.front();
        q.pop();

        // erase all words that has been used in the
        // previous levels to transform
        if (sequenceVector.size() > level) { // if on new level in queue
            level++;
            for (auto it : usedOnLevel) {
                st.erase(it); //visited
            }
            usedOnLevel.clear(); // for new level new guy store
        }

        string word = sequenceVector.back(); // the last guy in the sequence is that word
        // store the answer
        if(word == endWord) {
            // 1st sequence where we reached the end
            if(ans.size() == 0) {
                ans.push_back(sequenceVector);
            }
            else if (ans[0].size() == sequenceVector.size()) {
                ans.push_back(sequenceVector);
            }
        }

        for(int i=0; i < word.size(); i++) {
            char original = word[i];
            for(char ch = 'a'; ch <= 'z'; ch++) {
                word[i] = ch;
                if(st.count(word) > 0) {
                    // Check if the word is present in the wordList and
                    // push the word along with the new sequence in the queue.
                    sequenceVector.push_back(word);
                    q.push(sequenceVector);

                    // mark as visited on the level
                    usedOnLevel.push_back(word);
                    sequenceVector.pop_back();
                }
            }
            word[i] = original;
        }
    }

    return ans;
} 





// A comparator function to sort the answer.
bool comp(vector<string> a, vector<string> b) {
    string x = "", y = "";
    for (string i : a)
        x += i;
    for (string i : b)
        y += i;

    return x < y;
}


int main() {

    vector<string> wordList = {"des", "der", "dfr", "dgt", "dfs"};
    string startWord = "der", targetWord = "dfs";

    vector<vector<string>> ans = findSequences(startWord, targetWord, wordList);

    // If no transformation sequence is possible.
    if (ans.size() == 0)
        cout << -1 << endl;
    else {
        sort(ans.begin(), ans.end(), comp);
        for (int i = 0; i < ans.size(); i++) {
            for (int j = 0; j < ans[i].size(); j++) {
                cout << ans[i][j] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
