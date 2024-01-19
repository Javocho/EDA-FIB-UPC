#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<char>> Matrix;

vector<pair<int,int>> DIRS = {{1,0}, {0,1}, {-1,0}, {0,-1}};

void readMatrix(Matrix& M, int n, int m) {
	for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> M[i][j];
        }
    }
}

bool posOk(const Matrix& M, int r, int c) {
	return (r >= 0 and r < M.size() and c >= 0 and c < M[0].size());
}

int dfs(Matrix &M, int r, int c) {
	// cout << "estoy en pos " << r << " " << c << endl;
	if (posOk(M, r, c) and M[r][c] != 'X') {
		int t = 0;
		if (M[r][c] == 't') t++;
		M[r][c] = 'X';
		for (pair<int,int> p : DIRS) {
			t+= dfs(M, r+p.first, c+p.second);
		}
		return t;
	}
	return 0;
} 

int main() {
    int n, m, r, c;
    cin >> n >> m;
    Matrix M(n, vector<char>(m));
    readMatrix(M, n, m);
    cin >> r >> c;
	r--;
	c--;
	cout << dfs(M, r, c) << endl;
}

