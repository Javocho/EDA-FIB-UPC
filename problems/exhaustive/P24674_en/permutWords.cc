#include <iostream>
#include <vector>
#include <string>

using namespace std;

void printVector(const vector<string>& V) {
	bool first = true;
	for (string i : V) {
		if (first) cout << '(';
		if (not first) cout << ',';
		cout << i;
		if (first) first = false;
	}
	cout << ')';
	cout << endl;
}

void permutations(int n, vector<string> V, vector<bool>& used, int k, const vector<string> candidates) {
	if (k == n) printVector(V);
	else {
		for (int i = 0; i < n; i++) {
			if (not used[i]) {
				V[k] = candidates[i];
				used[i] = true;
				permutations(n, V, used, k+1, candidates);
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
	vector<string> V(n);
	vector<string> candidates(n);
	vector<bool> used(n + 1, false); //n + 1 porque empieza en 1

	for (int i = 0; i < n; i++) {
		cin >> candidates[i];
	}
	permutations(n, V, used, k, candidates);
}