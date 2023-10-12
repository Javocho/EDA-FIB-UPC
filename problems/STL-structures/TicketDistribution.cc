#include <string>
#include <iostream>
#include <queue>

using namespace std;

string s;

struct comp {
	bool operator()(string a, string b) {
		if (a.length() == b.length()) {
			string char_to_compare = s.substr(0, a.size());
			if (a == char_to_compare) return false;
			if (b == char_to_compare) return true;
			if (a < b) { //if a is less than b, it would be correctly sorted unless a is less than the word s and b is greater.
				if (a < char_to_compare and b > char_to_compare) return true;
				return false;
			}
			if (b < a) {
				if (a > char_to_compare and b < char_to_compare) return false;
				return true;
			}
		}
		return a.length() > b.length();
	}
};

int main() {
	while (cin >> s) {
		char action;
		int tickets = 0;
		string customer_code;
		priority_queue<string, vector<string>, comp> customers;
		while (cin >> action and action != 'E') {
			if (action == 'T') tickets++;
			else if (action == 'S') {
				cin >> customer_code;
				customers.push(customer_code);
			}
			while ((tickets > 0) and (not customers.empty())) {
				cout << customers.top() << endl;
				customers.pop();
				--tickets;
			}
		}
		cout << tickets << " ticket(s) left" << endl;
		cout << customers.size() << " supporter(s) with no ticket" << endl;
		cout << endl;
	}
}