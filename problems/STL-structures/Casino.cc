#include <map>
#include <string>
#include <iostream>

using namespace std;

int main() {
    string name, action;
    map<string, int> casino;
    map<string, int>::iterator it;

    while (cin >> name) {
        cin >> action;
        it = casino.find(name);
        if (action == "enters") {
            if (it == casino.end()) casino.insert(make_pair(name, 0));
            else cout << name << " is already in the casino" << endl;
        }
        else if (action == "leaves") {
            if (it == casino.end()) cout << name << " is not in the casino" << endl;
            else {
                cout << name << " has won " << it->second << endl; 
                casino.erase(name);
            }
        }
        else if (action == "wins") {
            int n;
            cin >> n;
            if (it == casino.end()) cout << name << " is not in the casino" << endl;
            else it->second += n;
        }
    }
    cout << "----------" << endl;
    it = casino.begin();
    while (it != casino.end()) {
        cout << it->first << " is winning " << it->second << endl;
        ++it;
    }
}