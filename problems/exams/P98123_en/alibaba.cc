#include <iostream>
#include <set>
using namespace std;

int main() {
	int n;
	unsigned long value;
	unsigned long sum = 0;
	string cmd;
	set<unsigned long> minS;
	cin >> n;
	set<unsigned long, greater<unsigned long>> bag;
	//en minS los que estamos sumando y en bag el resto
	while (cin >> cmd >> value) {
		if (cmd == "deixar") {
			if (minS.size() < n) {
				minS.insert(value);
				sum += value;
			}
			else {
				unsigned long min = *(minS.begin());
				if (value > min) {
					minS.insert(value);
					minS.erase(min);
					sum = sum - min + value;
					bag.insert(min);
				}
				else bag.insert(value);
			}
		}
		else {
			if (*(minS.begin()) <= value) {
				minS.erase(value);
				sum -= value;
				if (bag.size() > 0) {
					auto it = bag.begin();
					minS.insert(*it);
					sum += *it;
					bag.erase(it);
				}
			}
			else bag.erase(value);
		}
		cout << sum << endl;
	}	
}