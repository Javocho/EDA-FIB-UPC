#include <iostream>
#include <string>
#include <set>
#include <queue>

using namespace std;

struct strsize {
	bool operator() (const string& a, const string& b) const {
		if (a.size() < b.size()) return true;
		else if (a.size() > b.size()) return false;
		else return a < b;
	}
};

void print_game(set<string>& has, set<string, strsize>& had, int& ngame) {
    cout << "GAME #" << ngame << endl;
    ngame++;
    cout << "HAS:" << endl;
    for (auto it = has.begin(); it != has.end(); it++) {
        cout << *it << endl;
    }
	cout << endl;
    cout << "HAD:" << endl;
    for (auto it = had.begin(); it != had.end(); it++) {
        cout << *it << endl;
    }
	has.clear();
	had.clear();
}

int main() {
    set<string> has;
    set<string, strsize> had;
    string name;
    int ngame = 1;

    cin >> name;
    while (name != "QUIT") {
        if (name != "END") {
            auto it = has.find(name);
            if (it == has.end()) {
				has.insert(name);
				auto it2 = had.find(name);
				if (it2 != had.end()) had.erase(name);
			}
            else {
                has.erase(name);
                had.insert(name);
            }
        }
        else { 
			print_game(has, had, ngame);
			cout << endl;
		}
        cin >> name;
    }
    print_game(has, had, ngame);
    return 0;
}
