#include <iostream>
#include <vector>

using namespace std;

int position(double x, const vector<double>& v, int left, int right) {
	if (left > right) return -1;
	int middle = (left + right)/2;
	if (x > v[middle]) position(x, v, middle + 1, right);
	if (x < v[middle]) position(x, v, left, middle - 1);
	return middle;
}
