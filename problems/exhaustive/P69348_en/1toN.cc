#include <iostream>
#include <vector>

using namespace std;

void printVector(const vector<int>& V) {
	bool first = true;
	for (int i : V) {
		if (first) cout << '(';
		if (not first) cout << ',';
		cout << i;
		if (first) first = false;
	}
	cout << ')';
	cout << endl;
}

void permutations(int n, vector<int> V, vector<bool>& used, int k) {
	if (k == n) printVector(V);
	else {
		for (int i = 1; i <= n; i++) {
			if (not used[i]) {
				V[k] = i;
				used[i] = true;
				permutations(n, V, used, k+1);
				used[i] = false;
			}
		}
	}
}

int main() {
	int n;
	int k = 0;
	cin >> n;
	// n = 2;	
	vector<int> V(n);
	vector<bool> used(n + 1, false); //n + 1 porque empieza en 1
	permutations(n, V, used, k);
}