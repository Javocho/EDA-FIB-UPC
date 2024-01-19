#include <iostream>
#include <map>
using namespace std;


struct Info {
  string code;
  int price;
};


int main() {
  map<int, Info> M;
  char c;
  while (cin >> c) {
    if (c == 'n') {
      cout << "num: " << M.size() << endl;
    }
    else if (c == 'u') {
      string code;
      int length, price;
      cin >> code >> length >> price;
      auto it = M.find(length);
		if (it == M.end()) {
			Info i;
			i.code = code;
			i.price = price;
			M.insert({length, i});
		}
		else {
			it->second.code = code;
			it->second.price = price;
		}
    }
    else if (c == 'q') {
      int length;
      cin >> length;
      auto it = M.find(length);
	  if (it == M.end()) cout << "-1" << endl;
		else cout << (*it).second.price << endl;
    }
    else if (c == 'p') {
      cout << string(10, '-') << endl;
      auto it = M.begin();
	  while (it != M.end()) {
		cout << it->second.code << ' ' << it->first << ' ' << it->second.price << endl;
		it++;
	  }
      cout << string(10, '*') << endl;
    }
    else { // c == 's'
		if (M.size() < 2) cout << "no" << endl;
		else {
			auto it = M.begin();
			it++;
			cout << it->second.code << ' ' << it->first << ' ' << it->second.price << endl;
		}
	}
  }
}
