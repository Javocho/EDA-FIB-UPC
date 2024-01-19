#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef vector<vector<char>> Matrix;

const vector<pair<int, int>> DIR = {{-2,1},{-1,-2},{2,1},{1,2},{-2,-1},{1,-2},{2,-1},{-1,2}};

void readMatrix(Matrix& M, int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> M[i][j];
		}
	}
}

bool posOk(const Matrix& M, int i, int j) {
	return i >= 0 and j >= 0 and i < M.size() and j < M[0].size() and M[i][j] != 'X';
}

int bfs(Matrix &M, int i, int j) {
	queue<pair<int,int>> Q;
	vector<vector<int>> dist(M.size(), vector<int>(M[0].size(), -1));
	dist[i][j] = 0;
	Q.push({i,j});
	while (not Q.empty()) {
		int x = Q.front().first;
		int y = Q.front().second;
		Q.pop();
		if (M[x][y] == 'p') return dist[x][y];
		for (auto p : DIR) {
			// cout << x+p.first << " " << y+p.second << " " << posOk(M, x+p.first, y+p.second) << endl;
			if (posOk(M, p.first+x, p.second+y) and dist[p.first+x][p.second+y] == -1) {
				Q.push({p.first+x,p.second+y});
				dist[p.first+x][p.second+y] = dist[x][y] + 1;
			}
		}
	}
	return -1;
}


int main() {
	int n, m, i, j;
	while (cin >> n >> m) {
		Matrix M(n, vector<char>(m));
		readMatrix(M, n, m);
		cin >> i >> j;
		int dist = bfs(M, i-1, j-1);
		if (dist == -1) cout << "no" << endl;
		else cout << dist << endl;
	}
}