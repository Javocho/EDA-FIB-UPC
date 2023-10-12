#include <iostream>
#include <unordered_map>

using namespace std;

#define MAX_CALC 100000000

int collatz_calculus(int n, int x, int y) {
    if (n%2 == 0) n = n/2 + x;
    else n = 3*n + y;
    return (n);
}

int main() {
    int x, y, n;

    while (cin >> x >> y >> n)
    {
        int count;
        bool found;

        found = false;
        count = 0;
        unordered_map<int, int> collatz_map;
        collatz_map.insert(make_pair(n, count));
        while (not found and n <= MAX_CALC)
        {
            unordered_map<int, int>::const_iterator it;
            n = collatz_calculus(n, x, y);
            count++;
            it = collatz_map.find(n);
            if (it != collatz_map.end())
            {
                cout << count - it->second << endl;
                found = true;
            }
            else collatz_map.insert(make_pair(n, count));
        }
        if (not found) cout << n << endl;
        collatz_map.clear();
    }
}