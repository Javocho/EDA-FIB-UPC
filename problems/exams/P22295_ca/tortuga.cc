#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<char>> Matrix;

vector<pair<int, int>> Dir = {{0,1}, {1, 0}, {-1,0}, {0,-1}};

void readMatrix(Matrix& M, int x, int y) {
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			cin >> M[i][j];
		}
	}
}

void writeSolution(vector<char> solution) {
	for (int i = 0; i < solution.size(); i++) {
		cout << solution[i];
	}
	cout << endl;
}

bool pos_ok(const vector<vector<bool>>& V, int x, int y) {
	// cout << V.size() << " " << V[0].size() << " " << V[x][y] << endl;
	// cout << x << " " << y << endl;
	return (x < V.size() and x >= 0 and y < V[0].size() and y >= 0 and !V[x][y]);
}

void searchPaths(Matrix& M, int x, int y, const int final_x, const int final_y, vector<char> partial_solution, vector<vector<bool>>& visited) {
	if (pos_ok(visited, x, y)) {
		// cout << "estic a " << x << " " << y << " pos final " << final_x << " " << final_y <<  endl;
		partial_solution.push_back(M[x][y]);
		if (x == final_x and y == final_y) {
			writeSolution(partial_solution);
		}
		else {
			visited[x][y] = true;
			for (pair<int, int> p : Dir) {
				searchPaths(M, x + p.first, y + p.second, final_x, final_y, partial_solution, visited);
			}
			visited[x][y] = false;
		}
	}

}

int main() {
	int i, j, initial_i, initial_j, final_i, final_j;
	cin >> i >> j;
	Matrix rajoles(i, vector<char>(j));
	vector<vector<bool>> visited(i, vector<bool>(j, false));
	vector<char> partial_solution;
	readMatrix(rajoles, i, j);
	cin >> initial_i >> initial_j >> final_i >> final_j;
	searchPaths(rajoles, initial_i, initial_j, final_i, final_j, partial_solution, visited);
}