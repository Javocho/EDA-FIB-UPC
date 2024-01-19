#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef vector<char> Row;
typedef vector<Row> Matrix;
typedef vector<vector<bool>> MatrixBool;

vector<pair<int, int>> dirBishop = {{1,1}, {-1,-1}, {1,-1}, {-1,1}};
vector<pair<int, int>> dirKnight = {{-2, 1}, {-1, 2}, {2, -1}, {1, 2}, {2, 1}, {1, 2}, {-2, -1}, {-1, -2}};

void readMatrix(Matrix& M, int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> M[i][j];
		}
	}
}

bool posOk(const Matrix& M, int x, int y) {
	return (x >= 0 and x < M.size() and y >= 0 and y < M[0].size() and M[x][y] != 'T');
}


void bfsBishop(Matrix& M, int x, int y, int& coins) {
	queue<pair<int,int>> Q;
	int i, j, tmpi, tmpj;
	Q.push({x,y});
	while (not Q.empty()) {
		i = Q.front().first;
		j = Q.front().second;
		Q.pop();
		// cout << "bishop pos " << x << " " << y << endl;
		if (M[i][j] > '0' and M[i][j] <= '9') {
			coins += (M[i][j] - '0');
		}
		for (auto p : dirBishop) {
			tmpi = i+p.first;
			tmpj = j+p.second;
			if (posOk(M, tmpi, tmpj)) Q.push({tmpi, tmpj});
		}
		M[i][j] = 'T';
	}
}

void bfsKnight(Matrix& M, int x, int y, int& coins, int& ncoins) {
	queue<pair<int,int>> Q;
	int i, j, tmpi, tmpj;
	Q.push({x,y});
	while (not Q.empty()) {
		i = Q.front().first;
		j = Q.front().second;
		Q.pop();
		// cout << "bishop pos " << x << " " << y << endl;
		if (M[i][j] > '0' and M[i][j] <= '9') {
			coins += (M[i][j] - '0');
		}
		for (auto p : dirKnight) {
			tmpi = i+p.first;
			tmpj = j+p.second;
			if (posOk(M, tmpi, tmpj)) Q.push({tmpi, tmpj});
		}
		M[i][j] = 'T';
	}
}

int searchCoins(Matrix& M, int n, int m, int &ncoins) {
	int coins = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (M[i][j] == 'B' or M[i][j] == 'K') {
				if (M[i][j] == 'B') bfsBishop(M, i, j, coins);
				else if (M[i][j] == 'K') bfsKnight(M, i, j, coins, ncoins);
				if (ncoins == 0) return coins;
			} 
		}
	}
	return coins;
}

int main() {
	int n, m;
	int ncoins;
	while (cin >> n >> m) {
		Matrix M(n, Row(m));
		readMatrix(M, n, m);
		cout << searchCoins(M, n, m, ncoins) << endl;
	}
}