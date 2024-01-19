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

void zeros_one(vector<int> V, int n, int k) {
	if (n == 0) printVector(V);
	else {
		V[k] = 0;
		zeros_one(V, n - 1, k + 1);
		V[k] = 1;
		zeros_one(V, n - 1, k + 1);
	}
}

int main() {
	int n;
	int k = 0;
	cin >> n;
	vector<int> V(n);
	zeros_one(V, n, k);
}