#include <iostream>
#include <vector>
using namespace std;

int binary_search(int left, int right, double x, const vector<double>& v) {
	if (left > right) return -1;
	int mid = (left + right)/2;
	if (v[mid] < x) return binary_search(mid + 1, right, x, v);
	if (v[mid] > x) return binary_search(left, mid - 1, x, v);
	if (mid > 0) {
		int same_value = binary_search(left, mid - 1, x, v);
		if (same_value != -1) return same_value;
	}
	return mid;
}

int first_occurrence(double x, const vector<double>& v) {
	return (binary_search(0, v.size() - 1, x, v));
}


// int main() {
//     int n;
//     while (cin >> n) {
//         vector<double> V(n);
//         for (int i = 0; i < n; ++i) cin >> V[i];
// 		double x;
// 		cin >> x;
// 		cout << first_occurrence(x, V) << endl;
//     }
// }
