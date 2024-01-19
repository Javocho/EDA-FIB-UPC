#include <iostream>
#include <vector>

using namespace std;

int n, m;
typedef vector<vector<char>> matrix;


int treasure(matrix &mat, int x, int y, int t) {
    if (x >= 0 and x < n and y >= 0 and y < m) {
		int t = 0; //ME FALTABA ESTO ya se suman
        if (mat[x][y] == 't') t++;
        if (mat[x][y] == 'X') return 0;
        mat[x][y] = 'X';
        return (treasure(mat, x, y+1, t) + treasure(mat, x-1, y, t) + treasure(mat, x+1, y, t) + treasure(mat, x, y-1, t)); 
    }
    return t;
}

int main() {
    int r, c;
    cin >> n >> m;
	int t = 0;
    matrix mat(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mat[i][j];
        }
    }
    cin >> r >> c;
    cout << treasure(mat, r-1, c-1, t) << endl;
}

