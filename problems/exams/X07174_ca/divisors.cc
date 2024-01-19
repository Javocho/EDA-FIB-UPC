#include <iostream>
#include <vector>

using namespace std;

void readDivisors(vector<int>& div, int m) {
	for (int i = 0; i < m; i++) {
		cin >> div[i];
	}
}

bool numOk(vector<int> div, int n) {
	for (int d : div) {
		if ((n % d) == 0) return false;
	}
	return true;
}

void possibleNums(const vector<int>& div, int n, int k, int x) {
	if (k == n)
		cout << x << endl;
	else {
		for (int i = 0; i <= 9; i++) {
			int y = 10*x + i;
			if (numOk(div, y)) possibleNums(div, n, k+1, y);
		}
	}
}

int main() {
	int n, m;

	while (cin >> n >> m) {
		vector<int> div(m);
		readDivisors(div, m);
		possibleNums(div, n, 0, 0);
		cout << "----------" << endl;
	}
}