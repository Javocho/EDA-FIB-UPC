#include <iostream>
#include <math.h>

using namespace std;

bool flag_found;

int fastestExp(int c, int n) {
	if (n == 0) return 1;
	if (n % 2 == 0) return fastestExp(c, n/2)*fastestExp(c, n/2);
	else return fastestExp(c, (n-1)/2)*fastestExp(c, (n-1)/2)*c;
	return pow(c, n);
}

int main() {
	int c, n;
	cin >> c >> n;
	cout << fastestExp(c, n) << endl;
}