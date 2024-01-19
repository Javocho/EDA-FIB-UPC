#include <iostream>
#include <vector>
using namespace std;

const vector<char> LETTERS = {'A', 'C', 'G', 'T'};

void writeVector(const vector<char>& partial_sol) {
	for (int i = 0; i < partial_sol.size(); i++) {
		cout << partial_sol[i];
	}
	cout << endl;
}

void backtracking(int n, vector<char> partial_sol) {
	if (partial_sol.size() == n) writeVector(partial_sol);
	else {
		// cout << "hey" << endl;
		for (int i = 0; i < LETTERS.size(); i++) {
				partial_sol.push_back(LETTERS[i]);
				backtracking(n, partial_sol);
				partial_sol.pop_back();
		}
	}
}

int main() {
	int n;
	cin >> n;
	vector<char> partial_sol;
	backtracking(n, partial_sol);
}