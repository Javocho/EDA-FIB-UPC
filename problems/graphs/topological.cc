#include <iostream>
#include <vector>
#include <queue>
#include <list>

using namespace std;

typedef vector<vector<int>> Graph;

void read_graph(Graph& G, vector<int>& ge, int m) {
	for (int i = 0; i < m; i++)
	 {
		int n1, n2;
		cin >> n1 >> n2;
		G[n1].push_back(n2);
		ge[n2]++;
	 }
}

void write_list(const list<int>& L) {
	bool first = true;
	for (auto it = L.begin(); it != L.end(); it++) {
		if (not first) cout << ' ';
		cout << *it;
		if (first) first = false;
	}
	cout << endl;
}

priority_queue<int, vector<int>, greater<int>> make_degrees(const vector<int>& ge) {
	priority_queue<int, vector<int>, greater<int>> q;
	for (int i = 0; i < ge.size(); i++)
		if (ge[i] == 0) q.push(i);
	return q;
}

list<int> topological_sort(const Graph& G, vector<int>& ge, priority_queue<int, vector<int>, greater<int>>& q) {
	list<int> L;
	while (not q.empty()) {
		int v = q.top();
		q.pop();
		for (int w : G[v]) {
			ge[w]--;
			if (ge[w] == 0) q.push(w);
		}
		L.push_back(v);
	}
	return L;
}

int main() {
	int n, m;
	while (cin >> n >> m) {
		Graph G(n);
		vector<int> ge(n, 0);
		priority_queue<int, vector<int>, greater<int>> q;
		read_graph(G, ge, m);
		q = make_degrees(ge);
		list<int> L = topological_sort(G, ge, q);
		write_list(L);
	}
}
