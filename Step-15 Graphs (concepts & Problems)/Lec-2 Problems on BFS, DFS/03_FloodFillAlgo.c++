// Flood Fill Algorithm


/* // Link-> https://www.naukri.com/code360/problems/flood-fill-algorithm_1089687

void dfs(int x, int y, vector<vector<int>> &image, int newColor, int iniColor, vector<vector<int>> &ans, int delR[], int delC[]) {
    ans[x][y] = newColor;
    int n = image.size(), m = image[0].size();

    for(int i = 0; i < 4; i++) {
        int nr = x + delR[i];
        int nc = y + delC[i];

        if(nr >=0 && nr < n && nc >= 0 && nc < m && image[nr][nc] == iniColor && ans[nr][nc] != newColor) {
            dfs(nr, nc, image, newColor, iniColor, ans, delR, delC);
        }
    }
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int x, int y, int newColor) {
    // Write your code here.
    int iniColor = image[x][y];
    vector<vector<int>> ans = image;
    int delR[] = {-1, 0, 1, 0};
    int delC[] = {0, 1, 0, -1};
    dfs(x, y, image, newColor, iniColor, ans, delR, delC);

    return ans;
}


*/


#include<iostream>
#include<vector>
using namespace std;


void dfsHelper(int row, int col, vector<vector<int>>& image, int newColor, int initialColor, vector<vector<int>>& ans, int delRow[], int delCol[]) {
	int n = image.size(), m = image[0].size();
	ans[row][col] = newColor;

	for(int i=0; i < 4; i++) {
		int nR = row + delRow[i];
		int nC = col + delCol[i];

		if(nR >= 0 && nR < n && nC >= 0 && nC < m 
		&& image[nR][nC] == initialColor &&  ans[nR][nC] != newColor) {
			dfsHelper(nR, nC, image, newColor, initialColor, ans, delRow, delCol);
		}
	}
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
	int initialColor = image[sr][sc];
	vector<vector<int>> ans = image;
	int deltaR[] = {-1, 0, 1, 0};
	int deltaC[] = {0, 1, 0, -1};
	dfsHelper(sr, sc, image, newColor, initialColor, ans, deltaR, deltaC);

	return ans;
}


int main() {

    vector<vector<int>> image {
	    {1,1,1},
	    {1,1,0},
	    {1,0,1}
	};

    vector<vector<int>> ans = floodFill(image, 1, 1, 2);
	for(auto i: ans){
		for(auto j: i)
			cout << j << " ";
		cout << "\n";
    }

    return 0;
}
