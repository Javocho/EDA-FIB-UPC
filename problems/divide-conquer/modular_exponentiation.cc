#include <iostream>

using namespace std;

int exponential(int n, int k, int m) {
	if (k == 0) return 1;
	else {
		int aux = exponential(n, k/2, m)%m;

		if (k%2 == 0) return ((aux*aux)%m); // n^k = (n^(k/2))^2 cuando k es par
		else return (((aux*aux)%m)*n)%m; // n^k = ((n-1)/2 * (n-1)/2) cuando k es impar
	}
}

int main() {
	int n;
	while (cin >> n) {
		int k, m;
		cin >> k >> m;
		cout << exponential(n, k, m) << endl;
	}
}