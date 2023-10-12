#include <iostream>
#include <queue>

using namespace std;

int main() {
    char c;
    priority_queue<int> nums;

    while (cin >> c) {
        if ((nums.empty() and c != 'S') and (c >= 'A' and c <= 'Z')) cout << "error!" << endl;
        else {
            if (c == 'S')
            {
                int n;
                cin >> n;
                nums.push(n);
            }
            else if (c  == 'A') cout << nums.top() << endl;
            else if (c == 'R') nums.pop();
            else if (c == 'I') {
                int n;
                cin >> n;
                n += nums.top();
                nums.pop();
                nums.push(n);
            }
            else if (c == 'D') {
                int n;
                cin >> n;
                n = nums.top() - n;
                nums.pop();
                nums.push(n);
            }
        }
    }
}