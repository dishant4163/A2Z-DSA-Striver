//Recusrion Day-7 Challenge | Recursion - Subsets / Subsequences of String    


/* Subsequences of String (Coding Ninjas)->  https://bit.ly/33hi3MB     



*/





#include<bits/stdc++.h>
using namespace std;




//1. Print all subsets of a given Set or Array
void solve(vector<int> &nums, vector<int> &output, int index, vector<vector<int>> &ans) {
    //Base case
    if (index >= nums.size()) {
        // if only add Non-Empty subsets i.e not to to add empty subset
        // if(!output.empty()) // un-comment this to add empty subset
        ans.push_back(output);
        return;
    }

    // Exclude 
    solve(nums, output, index+1, ans);

    // include
    int element = nums[index];
    output.push_back(element);
    solve(nums, output, index+1, ans);

}


vector<vector<int> > subsets(vector<int> &nums) {
    vector<vector<int> > ans;
    vector<int> output;
    int index = 0;
    solve(nums, output, index, ans);
    return ans;
}




//2. Subsequences of String






int main() {

// Print all subsets of a given Set or Array
    vector<int> num = {1, 2, 3}; // Given input
    vector<vector<int>> result = subsets(num);
    
    // Print the subsets
    for (int i=0; i < result.size(); i++) {
        cout << "{ ";
        for (int j=0; j < result[i].size(); j++) {
            cout << result[i][j] << " ";
        }
        cout << "}" << endl;
    }




// Subsequences of String




    return 0;
}
