#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main() {
    cout.setf(ios::fixed);
	cout.precision(4);
    string cmd;
    int n, max;
    double average, total_elem;
    bool first = true;
    priority_queue<int, vector<int>, greater<int> > q;
    average = total_elem = 0;

    while (cin >> cmd)
    {
        if (cmd == "delete") {
            if (not q.empty()) {
                total_elem -= q.top();
                q.pop();
            }
            if (q.empty()) {
                cout << "no elements" << endl;
                first = true;
            }
        }
        else if (cmd == "number") {
            cin >> n;
            total_elem += n;
            q.push(n);
            if (first) {
                max = average = n;
                first = false;
            }
            else if (max < n) max = n;
        }
        if (not q.empty())
        {
            average = total_elem/q.size();
            cout << "minimum: " << q.top() << ", " << "maximum: " << max << ", " << "average: " << average << endl;
        }
    }
}