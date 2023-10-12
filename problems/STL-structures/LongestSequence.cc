#include <iostream>
#include <set>
#include <sstream>

using namespace std;

int main()
{
    string s;
    while (getline(cin, s)) {
        int n, count;
        set<int> nums;
        istringstream ss(s);
        while (ss >> n) nums.insert(n);
        count = 0;
        set<int>::const_iterator it = nums.begin();
        bool even;
        if (not nums.empty()) {
            if (*it % 2 == 0) even = true;
            else even = false;
            count++;
            it++;
            while (it != nums.end()) {
                if (not even and *it % 2 == 0) {
                    even = true;
                    count++;
                }
                if (even and *it % 2 != 0) {
                    even = false;
                    count++;
                }
                it++;
            }
        }
        cout << count << endl;
    }    
    return (0);
}
