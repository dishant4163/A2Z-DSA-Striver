// Maximum Rectangle Area with all 1's | DP on Rectangles



/* // Problem-Link-> https://www.naukri.com/code360/problems/maximum-size-rectangle-sub-matrix-with-all-1-s_893017   

#include<bits/stdc++.h>

int largestRectInHisto(vector<int>& ar) {
	int maxArea = 0;
	stack<int> st;
	ar.push_back(0);

	for(int i=0; i < ar.size(); i++) {
		while(!st.empty() && ar[st.top()] >= ar[i]) {
			int ht = ar[st.top()];
			st.pop();

			int wd = st.empty() ? i : i-st.top()-1;
			// (i-st.top()-1) to calculate the width of the rectangle
			maxArea = max(maxArea, ht * wd);
		}
		st.push(i);
	}
	return maxArea;
}

int maximalAreaOfSubMatrixOfAll1(vector<vector<int>> &mat, int n, int m){
	// Write your code here.
	int maxiArea = 0;
	vector<int> pSumAr(m, 0);

	for(int i=0; i < n; i++) {
		for(int j=0; j < m; j++) {
			if(mat[i][j] == 1) pSumAr[j]++;
			else pSumAr[j] = 0;
		}
		int histoArea = largestRectInHisto(pSumAr);
		maxiArea = max(maxiArea, histoArea);
	}
	return maxiArea;
}

*/



#include <bits/stdc++.h>
using namespace std;

int largestRectangleArea(vector<int> & histo) {
    int n = histo.size();
    stack<int> st;
    int maxAr = 0;

    for(int i = 0; i <= n; i++) {
        while(!st.empty() && (i==n || histo[st.top()] >= histo[i])) {
            int height = histo[st.top()];
            st.pop();

            int width;

            if(st.empty()) width = i;
            else width = i - st.top()-1;

            maxAr = max(maxAr, width*height);
        }

        st.push(i);
    }

    return maxAr;
}



// Soln-> TABULATION Approach
int maximalAreaOfSubMatrixOfAll1(vector<vector<int>> &mat, int n, int m)  {
    int maxAr = 0;
    vector<int> height(m, 0);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(mat[i][j] == 1) height[j]++;
            else height[j] = 0;
        }

        int area = largestRectangleArea(height);
        maxAr = max(maxAr, area);
    }

    return maxAr;
}



int main() {

    vector<vector<int>> mat = {
        {1, 0, 1, 0, 0}, 
        {1, 0, 1, 1, 1},
        {1, 1, 1, 1, 1}, 
        {1, 0, 0, 1, 0}
    };

    int n = 4, m = 5;

    cout << "Solve using TABULATION Approach " << endl;
    cout << "The Maximum Rectangle Area with all 1's is: " << maximalAreaOfSubMatrixOfAll1(mat, n, m) << endl << endl;


    return 0;
}
