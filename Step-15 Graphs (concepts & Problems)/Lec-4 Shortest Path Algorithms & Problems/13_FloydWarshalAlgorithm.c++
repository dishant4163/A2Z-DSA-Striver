// Floyd Warshall Algorithm aka Multisource Shortest Path Algo



/*// Problem-Link-> https://www.naukri.com/code360/problems/floyd-warshall_2041979

int floydWarshall(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    // Write your code here.

    vector<vector<int>> adjMatrix(n+1, vector<int>(n+1, 1e9));
    for(int i=0; i<edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];
        int wt = edges[i][2];

        adjMatrix[u][v] = wt;
    }

    for(int i=0; i <= n; i++) {
        for(int j = 0; j <= n; j++) {
            if(i == j) adjMatrix[i][j] = 0;
        }
    }
    

    for(int k = 1; k <= n; k++) {
        for(int i=1; i <= n; i++) {
            for(int j=1; j <= n; j++) {
                if(adjMatrix[i][k] != 1e9 && adjMatrix[k][j] != 1e9) {
                    adjMatrix[i][j] = min(adjMatrix[i][j], adjMatrix[i][k] + adjMatrix[k][j]);
                }
            }
        }
    }

    return adjMatrix[src][dest];

}


*/



#include<bits/stdc++.h>
using namespace std;


void shortest_distance(vector<vector<int>>& matrix) {
    int n = matrix.size();
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(matrix[i][j] == -1) {
                matrix[i][j] = 1e9;
            }
            // mark matrix diagonal zero
            if(i == j) matrix[i][j] = 0;
        }
    }

    // apply FLoyd Warshall algo 
    for(int via = 0; via < n; via++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                matrix[i][j] = min(matrix[i][j], matrix[i][via] + matrix[via][j]);
            }
        }
    }

    // // for detecting Negative cycle in graph
    // for(int i = 0; i < n; i++) {
    //     if(matrix[i][i] < 0) {
    //         cout << "-ve";
    //     }
    // }


    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(matrix[i][j] == 1e9) {
                matrix[i][j] = -1;
            }
        }
    }
}



int main() {

    int V = 4;
	vector<vector<int>> matrix(V, vector<int>(V, -1));
	matrix[0][1] = 2;
	matrix[1][0] = 1;
	matrix[1][2] = 3;
	matrix[3][0] = 3;
	matrix[3][1] = 5;
	matrix[3][2] = 4;

	shortest_distance(matrix);
    cout << "The output is: ";
	for (auto row : matrix) {
		for (auto cell : row) {
			cout << cell << " ";
		}
		cout << endl;
	}


    return 0;
}
