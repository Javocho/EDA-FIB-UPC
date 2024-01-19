#include <iostream>
#include <vector>

using namespace std;

void readVector(vector<int>& coins, int n, int& sum_total) {
	for (int i = 0; i < n; i++) {
		cin >> coins[i];
		sum_total += coins[i];
	}
}

int waysToAchieve(const vector<int>& coins, int sum, int x, int k, int sumtotal) {
	if (sum > x or sum + sumtotal < x) return 0;
	if (k == coins.size()) return 1;
	int ways = 0;
	for (int i = 1; i <= 2; i++) {
		ways += waysToAchieve(coins, sum+i*coins[k], x, k+1, sumtotal-i*coins[k]);
	}
	return ways;
}

int main() {
	int x, n, ways, sum, sum_total;
	while (cin >> x >> n) {
		ways = sum = sum_total = 0;
		vector<int> coins(n);
		readVector(coins, n, sum_total);
		waysToAchieve(coins, sum, x, 0, sum_total);
		cout << ways << endl;
	}
}