// Word Ladder-i


/* //Problem-Link-> https://www.naukri.com/code360/problems/word-ladder_1102319 


#include<bits/stdc++.h>
int wordLadder(string begin, string end, vector<string> &dict) {
	// Write your code here
	queue<pair<string, int>> q;
	q.push({begin, 1});
	unordered_set<string> st(dict.begin(), dict.end());
	st.erase(begin);

	while(!q.empty()) {
		string word = q.front().first;
		int steps = q.front().second;
		q.pop();

		if(word == end) return steps;

		for(int i=0; i < word.size(); i++) {
			char original = word[i];
			for(char ch = 'a'; ch <= 'z'; ch++) {
				word[i] = ch;

				if(st.find(word) != st.end()) {
					st.erase(word);
					q.push({word, steps + 1});
				}
			}
			word[i] = original;
		}
	}
	return -1;
}

*/


#include<iostream>
#include<vector>
#include<queue>
#include<unordered_set>
using namespace std;




int wordLadderLength(string startWord, string targetWord, vector<string> &wordList) {
    queue<pair<string, int>> q;
    q.push({startWord, 1});
    unordered_set<string> st(wordList.begin(), wordList.end());
    st.erase(startWord);

    while(!q.empty()) {
        string word = q.front().first;
        int steps = q.front().second;
        q.pop();

        if(word == targetWord) return steps;

        for(int i=0; i < word.size(); i++) {
            // Now, replace each character of ‘word’ with char
            // from a-z then check if ‘word’ exists in wordList.
            char original = word[i];
            for(char ch = 'a'; ch <= 'z'; ch++) {
                word[i] = ch;
                // check if it exists in the set and push it in the queue
                if(st.find(word) != st.end()) {
                    st.erase(word);
                    q.push({word, steps + 1});
                }
            }
            word[i] = original;
        }
    }
    return 0;
}


int main() {

    vector<string> wordList = {"des", "der", "dfr", "dgt", "dfs"};
    string startWord = "der", targetWord = "dfs";

    int ans = wordLadderLength(startWord, targetWord, wordList);

    cout << ans << endl;


    return 0;
}


/* Complexity Analysis:
Time Complexity: O(N * M * 26)

Where N = size of wordList Array and M = word length of words present in the wordList..

  Note that, hashing operations in an unordered set takes O(1) time, but if you want to use set here, 
  then the time complexity would increase by a factor of log(N) as hashing operations in a set take O(log(N)) time.



   Space Complexity:  O( N ) { for creating an unordered set and copying all values from wordList into it }

Where N = size of wordList Array.
*/
