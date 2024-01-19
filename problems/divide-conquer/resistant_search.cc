#include <iostream>
#include <vector>
using namespace std;


bool resistant_search(double x, const vector<double>& v) {
    int left = 0;
    int right = v.size() - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2; // Calculate the middle index.
        
        if (v[mid] == x) {
            return true; // Element found.
        }
        
        if (mid + 1 <= right && v[mid + 1] == x) {
            return true; // Check the element to the right.
        }
        
        if (mid - 1 >= left && v[mid - 1] == x) {
            return true; // Check the element to the left.
        }
        
        if (v[mid] < x) {
            left = mid + 2; // Skip mid and mid+1 since they've been checked.
        } else {
            right = mid - 2; // Skip mid and mid-1 since they've been checked.
        }
    }
    
    return false; // Element not found.
}

// int main() {
//     int n;
//     while (cin >> n) {
//         vector<double> V(n);
//         for (int i = 0; i < n; ++i) cin >> V[i];
// 		double x;
// 		while(cin >> x) cout << resistant_search(x, V) << endl;
//     }
// }	