#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<char>> Matrix;


struct Pos {
	int x;
	int y;
};

vector<Pos> ghostDir = {{0,1},{1,0},{-1,0},{0,-1},{1,-1},{-1,1},{1,1},{-1,-1}};

vector<Pos> pacDir = {{1,0},{0,1},{-1,0},{0,-1}};

void readMatrix(Matrix& M, int n, int m, Pos& initial_pac) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> M[i][j];
			if (M[i][j] == 'P') {
				initial_pac.x = i;
				initial_pac.y = j;
			}
		}
	}
}

bool posOk(const Matrix &M, const Pos& p) {
	return (p.x >= 0 and p.x < M.size() and p.y >= 0 and p.y < M[0].size());
}

bool danger(const Matrix &M, const Pos& p) {
	for (Pos tmp : ghostDir) {
		if (posOk(M, p) and M[p.x+tmp.x][p.y+tmp.y] == 'F') return true;
	}
	return false;
}


bool dfs(Matrix &M, Pos pac) {
	if (posOk(M, pac) and M[pac.x][pac.y] != 'X' and !danger(M, pac)) {
		// cout << "estoy en pos " << pac.x << " " << pac.y << endl;
		if (M[pac.x][pac.y] == 'B') return true;
		M[pac.x][pac.y] = 'X';
		for (Pos tmp : pacDir) {
			if (dfs(M, {pac.x+tmp.x, pac.y+tmp.y})) return true;
		}
	}
	return false;
}

int main() {
	int n,m;
	Pos initial_pac;

	while (cin >> n >> m) {
		Matrix M(n,vector<char>(m));
		readMatrix(M, n, m, initial_pac);
		if (dfs(M, initial_pac)) cout << "si" << endl;
		else cout << "no" << endl;
	}
}