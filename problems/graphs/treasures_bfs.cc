#include <iostream>
#include <vector>
#include <list>
#include <stack>

using namespace std;

typedef vector< vector<char> > Matrix;

int n, m;

int min_bfs(Matrix& mat) {
	int dist = 0;
	
}

int main() {
    int r, c;
    cin >> n >> m;
    Matrix mat(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mat[i][j];
        }
    }
    cin >> r >> c;
	cout << min_bfs(mat) << endl;
}