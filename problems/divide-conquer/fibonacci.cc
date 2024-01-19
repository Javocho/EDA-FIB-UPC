#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int>> Matrix;

Matrix mult_M(const Matrix& aux1, const Matrix& aux2, Matrix& M2, int m) {
	M2 = Matrix(2, vector<int> (2,0));
	
	for(int i = 0; i < 2; ++i) {
		for (int j = 0; j < 2; ++j) {
			for (int k = 0; k < 2; ++k) M2[i][j] += aux1[i][k]*aux2[k][j];
			M2[i][j] %= m;
		}
	}
	return M2;
}

void exp_M(const Matrix& M, Matrix& M2, int n, int m) { //M2 resultant, M la matriu que va generant fibonacci [1,1,1,0] i aux cada operació
	if (n == 0) {
		M2[0][0] = M2[1][1] = 1; //matriu identitat
		M2[0][1] = M2[1][0] = 0;
	}
	else if (n == 1) { // Mres = M
		M2[0][0] = M[0][0]%m;
		M2[0][1] = M[0][1]%m;
		M2[1][0] = M[1][0]%m;
		M2[1][1] = M[1][1]%m;
	} 
	else if (n%2 == 0) { //si es parell M^(n/2) * M^(n/2) = M^n
		Matrix aux(2, vector<int>(2));
		exp_M(M, aux, n/2, m);
		mult_M(aux, aux, M2, m);
	}
	else if (n%2 != 0) { //si es senar M^(n-1) * M^1 = M
		Matrix aux(2, vector<int>(2));
		exp_M(M, aux, n-1, m);
		mult_M(M, aux, M2, m);
	}
}

int main() {
	Matrix M(2, vector<int> (2, 1));
	int n, m;
	M[1][1] = 0;
	while(cin >> n >> m) {
		Matrix M2(2, vector<int> (2));
		exp_M(M, M2, n, m);
		cout << M2[0][1] << endl;
	}
}