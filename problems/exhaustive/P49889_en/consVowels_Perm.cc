//vector de posiciones de vocales y consonantes 
//usar mucho si es posición par o impar
//booleanos para indicar si esa vocal o consonante está usada
//Default parameters func(int k = 0) si usuario no da valor a k, se le dá 0 por defecto

#include <iostream>
#include <vector>

using namespace std;

void readVector(vector<char>& cons, vector<char>& vowels, int n) {
	for (int i = 0; i < n; i++) {
		cin >> cons[i];
	}
	for (int j = 0; j < n; j++) {
		cin >> vowels[j];
	}
}

void printVector(int n, const vector<char>& cons, const vector<char>& vowels, const vector<int>& partialPerm) {
	for (int i = 0; i < 2*n; i++) {
		if (i % 2 == 0) cout << cons[partialPerm[i]];
		else cout << vowels[partialPerm[i]];
	}
	cout << endl;
}

void generate_words(int n, int k, const vector<char>& cons, const vector<char>& vowels, vector<int>& partialPerm, vector<bool>& consUsed, vector<bool>& vowelUsed) {
	if (k == 2*n) printVector(n, cons, vowels, partialPerm);
	else {
		int vowelOrCons = k%2;
		for (int j = 0; j < n; j++) {
			if (vowelOrCons == 0 and not consUsed[j]) {
				partialPerm[k] = j;
				consUsed[j] = true;
				generate_words(n, k+1, cons, vowels, partialPerm, consUsed, vowelUsed);
				consUsed[j] = false;
			}
			else if(vowelOrCons == 1 and not vowelUsed[j]) {
				partialPerm[k] = j;
				vowelUsed[j] = true;
				generate_words(n, k+1, cons, vowels, partialPerm, consUsed, vowelUsed);
				// if (k == 1)
				// 	cout << consUsed[0] << ' ' << consUsed[1] << endl;
				vowelUsed[j] = false;
			}
		}
	}
}

int main() {
	int n;
	cin >> n;
	vector<bool> consUsed(n, false);
	vector<bool> vowelUsed(n, false);
	vector<char> cons(n);
	vector<char> vowels(n);
	vector<int> partialPerm(2*n);
	int k = 0;
	readVector(cons, vowels, n);
	generate_words(n, k, cons, vowels, partialPerm, consUsed, vowelUsed);
}