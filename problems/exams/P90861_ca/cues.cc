#include <iostream>
#include <vector>
#include <queue>
#include <sstream>

using namespace std;

void readQueues(vector<queue<string>>& vQ) {
	string s;
	for (int k = 0; k < vQ.size(); ++k) {
		string line;
		getline (cin, line);
		istringstream in(line);
		string name;
		while (in >> name) vQ[k].push(name);
	}
}

void writeCues(vector<queue<string>>& cues, queue<string>& sortit) {
	cout << "SORTIDES" << endl;
	cout << "--------" << endl;
	while (not sortit.empty()) {
		cout << sortit.front() << endl;
		sortit.pop();
	}
	cout << endl;
	cout << "CONTINGUTS FINALS" << endl;
	cout << "-----------------" << endl;
	for (int i = 0; i < cues.size(); i++) {
		cout << "cua " << i+1 << ":";
		while (not cues[i].empty()) {
			cout << ' ';
			cout << cues[i].front();
			cues[i].pop();
		}
		cout << endl;
	}
}

int main() {
	int n, cua;
	string cmd, name;
	queue<string> sortit;

	cin >> n;
	getline (cin, cmd); 
	vector<queue<string>> cues(n);
	readQueues(cues);
	while (cin >> cmd) {
		if (cmd == "SURT") {
			cin >> cua;
			if (cua > 0 and cua <= n and not cues[cua-1].empty()) {
				sortit.push(cues[cua-1].front());
				cues[cua-1].pop();
			}
		}
		else {
			cin >> name >> cua;
			if (cua > 0 and cua <= n) {
				cues[cua-1].push(name);
			}
		}
	}
	writeCues(cues, sortit);
}