#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<bool> col, diag1, diag2; //si hay ocupada la columna y la diagonal ascendente o descendente
//fila no hay que controlarla porque nunca se va a repetir, en recursión siempre se suma a i que es la fila
vector<int> t;

void write_matrix(int n) {
	for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) 
		if (t[i] == j) cout << 'Q';
		else           cout << '.';
     	 cout << endl;
    }
    cout << endl;
}

void reines(int i, int n) {
	if (n == i) write_matrix(n);
	else {
		int res = 0;
		for (int j = 0; j < n; j++) { //col per reina de fila i
			if (not col[j] and not diag1[i+j] and not diag2[i-j+n+1]) { //no veo mucho sentido diag2
				t[i] = j; //es pot escriure directament el mapa amb les reines?
				col[j] = diag1[i+j] = diag2[i-j+n+1] = true;
				reines(i+1, n);
				col[j] = diag1[i+j] = diag2[i-j+n+1] = false; //por qué se pone a false luego backtracking
			}
		}
	}
}

int main() {
	int n, m;
	m = 0; 
	cin >> n;
	col = vector<bool>(n);
	diag1 = diag2 = vector<bool>(2*n-1, false); 
	// t = vector<vector<char>>(n, vector<char>(n, '.'));
	t = vector<int>(n);
	reines(0, n);
}