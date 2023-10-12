#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    string cmd;
    map<string, int> bag;

    while (cin >> cmd)
    {
        if (cmd == "maximum?")
        {
            if (bag.empty()) cout << "indefinite maximum" << endl;
            else {
                auto it = bag.end();
                it--;
                cout << "maximum: " << it->first << ", " << it->second << " time(s)" << endl;
            }
        }
        else if (cmd == "minimum?")
        {
            if (bag.empty()) cout << "indefinite minimum" << endl;
            else {
                auto it = bag.begin();
                cout << "minimum: " << it->first << ", " << it->second << " time(s)" << endl;
            }
        }
        else if (cmd == "store")
        {
            string word;
            cin >> word;
            auto it = bag.find(word);
            if (it == bag.end()) bag.insert(make_pair(word, 1));
            else it->second++;
        }
        else if (cmd == "delete")
        {
            string word;
            cin >> word;
            auto it = bag.find(word);
            if (it != bag.end()) {
                it->second--;
                if (it->second < 1) bag.erase(it);
            }
        }
    }
}