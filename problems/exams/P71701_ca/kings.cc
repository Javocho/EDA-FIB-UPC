#include <iostream>
#include <vector>

using namespace std;

typedef vector<char> Fila;
typedef vector<Fila> Chess;

vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}, {1, -1}, {-1, 1}, {1, 1}, {-1, -1}};

void writeChess(const Chess& C) {
    for (const auto& row : C) {
        for (char cell : row) {
            cout << cell;
        }
        cout << endl;
    }
    cout << "----------" << endl;
}

bool posOk(int x, int y, int n) {
    return (x >= 0 and x < n and y >= 0 and y < n);
}

bool okKing(const Chess& C, int n, int x, int y) {
    if (!posOk(x, y, n)) return false;
    for (auto p : dir) {
        int newX = x + p.first;
        int newY = y + p.second;
        if (posOk(newX, newY, n) and C[newX][newY] == 'K') return false;
    }
    return true;
}

void placeKings(Chess& C, int x, int y, int n, int r) {
    if (r == 0) {
        writeChess(C);
        return;
    }
	if (x == n) return ;
	if (y == n) placeKings(C, x+1, 0, n, r);
	else { //si no pongo else me hace llamada recursiva de llamada recursiva --> sin control
		if (okKing(C, n, x, y)) {
			C[x][y] = 'K';
			r--;
			placeKings(C, x, y+1, n, r);
			C[x][y] = '.';
			r++;
		}
		placeKings(C, x, y+1, n, r);	
	}
}

int main() {
    int n, r;
    cin >> n >> r;

    Chess board(n, Fila(n, '.'));

    placeKings(board, 0, 0, n, r);


    return 0;
}
