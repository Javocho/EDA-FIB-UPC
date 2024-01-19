#include <iostream>
#include <vector>

using namespace std;

void writeRosers(const vector<char>& sol) {
	for (char c : sol) cout << c;
	cout << endl;
}

void bt(int n, int k, vector<char> sol_parcial, int parell) {
	
}

int main() {
	int n;
	while (cin >> n) {
		vector<char> sol(3*n);
		int parell = 0;
		bt(n, 0, sol, parell);
		cout << "**********" << endl;
	}
}