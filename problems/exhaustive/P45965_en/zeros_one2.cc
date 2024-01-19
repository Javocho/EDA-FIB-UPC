#include <iostream>
#include <vector>

using namespace std;

void printVector(const vector<int>& V) {
	bool first = true;
	for (int i : V) {
		if (not first) cout << ' ';
		cout << i;
		if (first) first = false;
	}
	cout << endl;
}

void zeros_one(vector<int>& V, int k, int ones) { //intento pasar V ref para evitar bomba aaaa
	if (k == V.size()) {
		int c = 0;
		if (ones == 0) printVector(V);
	}
	else {
		V[k] = 0;
		zeros_one(V, k + 1, ones);
		V[k] = 1;
		zeros_one(V, k + 1, ones - 1);
	}
}

int main() {
	int n, ones;
	int k = 0;
	cin >> n >> ones;
	vector<int> V(n);
	zeros_one(V, k, ones);
}