/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <vector>
#include <queue> 

using namespace std;

typedef vector<vector<char>> Matrix;

const vector<pair<int, int>> dir = {{0,1}, {1,0}, {-1,0}, {0,-1}};

void readMatrix(Matrix& M, int x, int y) {
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            cin >> M[i][j];
        }
    }
}

bool validPos(const Matrix& M, int i, int j) {
    return i < (int)M.size() and j < (int)M[0].size() and i >= 0 and j >= 0 and M[i][j] != 'X';
}

int bfsPath(Matrix& M, int i, int j) {
	vector<vector<int>> dist(M.size(), vector<int>(M[0].size(), -1));
	int new_i, new_j;
	int max = -1;
	queue<pair<int, int>> Q;
	Q.push(make_pair(i,j));
	dist[i][j] = 0;
	while (not Q.empty()) {
		auto qpair = Q.front();
		new_i = qpair.first;
		new_j = qpair.second; 
		Q.pop();
		if (M[new_i][new_j] == 't') {
			if (max < dist[new_i][new_j]) max = dist[new_i][new_j];
		}
		for (pair<int,int> p : dir) {
			if (validPos(M, new_i+p.first, new_j+p.second) and dist[new_i+p.first][new_j+p.second] == -1) {
				// cout << "push"<<endl;
				Q.push(make_pair(new_i+p.first, new_j+p.second));
				dist[new_i+p.first][new_j+p.second] = dist[new_i][new_j] + 1;
			}
		}
	}
	return max;
}

int main()
{
    int x,y, max;
    int i, j;
    cin >> x >> y;
	// x = 7;
	// y = 6;
    Matrix M(x, vector<char>(y));
    readMatrix(M, x, y);
	// M = {
    //     {' ', '.', 't', '.', '.', '.'},
    //     {' ', '.', 'X', 'X', 'X', '.'},
    //     {'.', '.', '.', '.', '.', '.'},
    //     {'t', 'X', '.', '.', 'X', '.'},
    //     {'.', 'X', '.', '.', 'X', 't'},
    //     {'.', 'X', 'X', '.', '.', '.'},
    //     {'.', '.', 't', '.', '.', '.'}
    // };
	cin >> i >> j;
	// i = 5;
	// j = 3;
    max = bfsPath(M, i-1, j-1);
	if (max == -1) cout << "no treasure can be reached" << endl;
    else cout << "maximum distance: " << max << endl;
}


