#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int>> Chess;

void readMatrix(Chess& C, int fil, int col, int& ncells, int& sum) {
	string input;
	for (int i = 0; i < fil; i++) {
		for (int j = 0; j < col; j++) {
			cin >> input;
			if (input == "X") C[i][j] = -1;
			else {
				int n = atoi(input.c_str());
				sum += n;
				C[i][j] = n; //suciedad
				ncells++;
			}
		}
	}
}



bool validPosition(const Chess& C, int v, int w) {
	if (v < 0 or w < 0 or v >= (int)C.size() or w >= (int)C[0].size() or C[v][w] == -1) return false;
	return true;
}

bool dfsComponent(const Chess& C, vector<vector<bool>>& visited, int v, int w, int& tmpsum, int& ncells, const int distribution) {
	if (validPosition(C, v, w)) {
		visited[v][w] = true;
		tmpsum += C[v][w];
		ncells++;
		if (not dfsComponent(C, visited, v+1, w+1, tmpsum, ncells, distribution)) return false;
		if (not dfsComponent(C, visited, v-1, w+1, tmpsum, ncells, distribution)) return false;
		//cout << tmpsum << ' ' << ncells << endl;
		if (tmpsum / ncells != distribution) return false;
	}
	return true;
}

bool bishopDistribution(const Chess& C, const int distribution) {
	vector<vector<bool>> visited(C.size(), vector<bool>(C[0].size(), false));
	bool connex = true;
	int ncells, tmpsum;
	for (int v = 0; v < C.size(); v++) {
		for(int w : C[v]) {
			if (validPosition(C, v, w)) {
				ncells = tmpsum = 0;
				if (not visited[v][w] and C[v][w] != -1) connex = dfsComponent(C, visited, v, w, tmpsum, ncells, distribution);
				if (not connex) return false;
			}
		}
	}
	return true;

	//miro para cada componente si se puede distribuir el número de alfileres entre las casillas

	//llamo a un dfs que me mire camino conexo contando num de casillas y número de alfileres
}

int main() {
	int cases, fil, col;
	cin >> cases;
	for (int i = 1; i <= cases; i++) {
		cin >> fil >> col;
		Chess C(fil, vector<int>(col));
		int cells, sumcells;
		sumcells = cells = 0;
		readMatrix(C, fil, col, cells, sumcells);
		if (cells == 0) cout << "Case " << i << ": yes" << endl;
		else if (sumcells % cells != 0) cout << "Case " << i << ": no" << endl;
		else if (not bishopDistribution(C, sumcells/cells)) cout << "Case " << i << ": no" << endl;
		else cout << "Case " << i << ": yes" << endl;
	}
}