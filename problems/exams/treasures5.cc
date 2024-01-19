#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef vector<char> Fila;
typedef vector<Fila> Matrix;

vector<pair<int,int>> dir = {{1,0}, {0,1}, {-1,0}, {0,-1}};

void readMatrix(Matrix &M, int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> M[i][j];
		}
	}
}

bool posOk(const Matrix& M, int i, int j, int n, int m) {
	return i >= 0 && j >= 0 && i < n && j < m && M[i][j] != 'X';
}


int bfs(Matrix& M, int i, int j, int n, int m) {
	vector<vector<int>> dist(n, vector<int>(m, -1));
	queue<pair<int,int>> Q;
	dist[i][j] = 0;
	Q.push({i,j});
	priority_queue<int> qtreasure;

	while (not Q.empty()) {
		auto p = Q.front();
		Q.pop();
		int x = p.first;
		int y = p.second;
		//cout << "estoy en " << x << " " << y << "que es " << M[x][y] << endl;
		if (M[x][y] == 't') {
				qtreasure.push(dist[x][y]);
				// cout << "puesto " << dist[x][y];
		}
		for (auto axe : dir) {
			if (posOk(M, x+axe.first, y+axe.second, n, m) && dist[x+axe.first][y+axe.second] == -1) {
				Q.push({x+axe.first, y+axe.second});
				dist[x+axe.first][y+axe.second] = dist[x][y] + 1;
			}
		}
	}
	if (qtreasure.size() < 2) return -1;
	// cout << "lo primero " << qtreasure.top() << endl;
	qtreasure.pop();
	// cout << "lo primero " << qtreasure.top() << endl;
	return qtreasure.top();
}

int main() {
	int n, m, i, j;
	cin >> n >> m;
	Matrix M(n, vector<char>(m));
	readMatrix(M, n, m);
	cin >> i >> j;
	int max = bfs(M, i-1, j-1, n, m);
	if (max == -1) cout << "we cannot reach two or more treasures" << endl;
	else cout << "second maximum distance: " << max << endl;
}