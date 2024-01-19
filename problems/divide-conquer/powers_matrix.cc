#include <vector>
#include <iostream>
using namespace std;
//fer exp ràpida

typedef vector<vector<int>> Matriu;

void llegirMatriu(Matriu &M) {
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			cin >> M[i][j];
		}
	}
}

Matriu mult_matrius(const Matriu &m1, const Matriu &m2, int m) {
	Matriu M(2, vector<int>(2));
	M[0][0] = ((m1[0][0]*m2[0][0])%m + (m1[0][1]*m2[1][0])%m)%m;
    M[0][1] = ((m1[0][0]*m2[0][1])%m + (m1[0][1]*m2[1][1])%m)%m;
    M[1][0] = ((m1[1][0]*m2[0][0])%m + (m1[1][1]*m2[1][0])%m)%m;
    M[1][1] = ((m1[1][0]*m2[0][1])%m + (m1[1][1]*m2[1][1])%m)%m;

	return M;
}

Matriu exponential(const Matriu &m1, int n, int m) {
	Matriu M(2, vector<int>(2, 0));
	if (n == 0) {
		M[0][0] = 1;
		M[1][1] = 1;
	}
	else {
		M = exponential(m1, n/2, m);
		if (n % 2 == 0) {
			M = mult_matrius(M, M, m);
		}
		else {
			M = mult_matrius(M, M, m);
			M = mult_matrius(M, m1, m);
		}
	}
	return M;
}

int main() {
	int n,m;
	Matriu M(2, vector<int>(2));
	for (int i = 0; i < 4; i++) {
		llegirMatriu(M);
		cin >> n >> m;
		M = exponential(M, n, m);
		cout << M[0][0] << ' ' << M[0][1] << endl;
        cout << M[1][0] << ' ' << M[1][1] << endl;
        cout << "----------" << endl;
	}
}