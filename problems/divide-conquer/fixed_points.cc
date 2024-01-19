#include <iostream>
#include <vector>

using namespace std;

int fixed_search(const vector<int>& v, int a, int left, int right) {
    if (left > right) return -1;
    int mid = (left + right)/2;
    if ((v[mid] + a) < mid + 1) return fixed_search(v, a, mid + 1, right);
    else if ((v[mid] + a) > mid + 1) return fixed_search(v, a, left, mid - 1);
    if (mid > 0) {
		int same_value = fixed_search(v, a, left, mid - 1);
		if (same_value != -1) return same_value;
	}
    return mid;
}

int main() {
    int n, m, a, seq;
	seq = 1;
    while (cin >> n) {
		vector<int> v(n);
		for (int i = 0; i < n; ++i) {
			cin >> v[i];
		}
		cout << "Sequence #" << seq << endl;
		++seq;
		cin >> m;
		for (int i = 0; i < m; ++i) {
			cin >> a;
			int fixed = fixed_search(v, a, 0, v.size() -1);
			if (fixed == -1) cout << "no fixed point for " << a << endl;
			else cout << "fixed point for " << a << ": " << fixed + 1 << endl;
		}
		cout << endl;
	}
}