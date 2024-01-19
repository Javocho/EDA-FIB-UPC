#include <iostream>
#include <vector>

using namespace std;

int n, m;
typedef vector<vector<char>> matrix;


bool treasure(matrix &mat, int x, int y) {
    if (x >= 0 and x < n and y >= 0 and y < m) {
        if (mat[x][y] == 't') return true;
        if (mat[x][y] == 'X') return false;
        mat[x][y] = 'X';
        return (treasure(mat, x, y+1) or treasure(mat, x-1, y) or treasure(mat, x+1, y) or treasure(mat, x, y-1)); 
    }
    return false;
}

int main() {
    int r, c;
    cin >> n >> m;
    matrix mat(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mat[i][j];
        }
    }
    cin >> r >> c;
    if (treasure(mat, r-1, c-1)) cout << "yes" << endl;
    else cout << "no" << endl;
}

