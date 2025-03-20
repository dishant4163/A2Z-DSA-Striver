// Word Ladder-ii (only for LeetCode not for interviews)

// LeetCode-Link->  https://leetcode.com/problems/word-ladder-ii/description/    


#include<bits/stdc++.h>
using namespace std;



// Soltuion only for LEETCODE
class Solution {
    // in CP most of the things Declare Globally
    unordered_map<string, int> mpp; // for stroing mini. distance
    vector<vector<string>> ans;
    string start; 

private:
    void dfs(string word, vector<string>& seq) {
        if(word == start) {
            reverse(seq.begin(), seq.end());
            ans.push_back(seq);
            reverse(seq.begin(), seq.end());
            return;
        }

        int steps = mpp[word];
        int s = word.size();
        for(int i = 0; i < s; i++) {
            char original = word[i];
            for(char ch = 'a'; ch <= 'z'; ch++) {
                word[i] = ch;
                if(mpp.find(word) != mpp.end() && mpp[word] + 1 == steps) {
                    seq.push_back(word);
                    dfs(word, seq);
                    seq.pop_back();
                }
            }
            word[i] = original;
        }
    }

public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        start = beginWord;
        queue<string> q;
        q.push({beginWord});
        mpp[beginWord] = 1;
        st.erase(beginWord);
        int sz = beginWord.size();

        while(!q.empty()) {
            string word = q.front();
            int steps = mpp[word];
            q.pop();

            if(word == endWord) break;

            for(int i = 0; i < sz; i++) {
                char original = word[i];
                for(char ch = 'a'; ch <= 'z'; ch++) {
                    word[i] = ch;
                    if(st.count(word)) {
                        q.push(word);
                        st.erase(word); // erase from set so that not to re-iterate on it 
                        mpp[word] = steps + 1; // store the steps;
                    }
                }

                word[i] = original;
            }
        }

        if(mpp.find(endWord) != mpp.end()) {
            vector<string> seq;
            seq.push_back(endWord);
            dfs(endWord, seq);
        }
        return ans;
    }
};




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

    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
    string startWord = "hit", targetWord = "cog";

    Solution soln;

    vector<vector<string>> ans = soln.findLadders(startWord, targetWord, wordList);

cout << "The output of Word Ladder-ii is: " << endl << endl;

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

    cout << endl;

    return 0;
}