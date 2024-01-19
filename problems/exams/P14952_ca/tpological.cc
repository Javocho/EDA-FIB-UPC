#include <iostream>
#include <vector>
#include <list>
#include <queue>

using namespace std;

typedef vector<vector<int>> Graph;
typedef priority_queue<int, vector<int>, greater<int>> Prio;

void readGraph(Graph& G, vector<int>& degree, Prio& degQ,  int e) {
	int v1, v2;
	for (int i = 0; i < e; i++) {
		cin >> v1 >> v2;
		G[v1].push_back(v2);
		degree[v2]++;
	}
	for (int i = 0; i < degree.size(); i++) {
		if (degree[i] == 0) degQ.push(i);
	}
}

void writeOrder(const list<int>& L) {
	bool first = true;
	for (int v : L) {
		if (first) first = false;
		else cout << " ";
		cout << v;
	}
	cout << endl;
}

list<int> topological(Graph &G, vector<int>& degree, Prio& degQ) {
	list<int> L;
	while (not degQ.empty()) {
		int v = degQ.top();
		degQ.pop();
		L.push_back(v);
		for (int i = 0; i < G[v].size(); i++) {
			degree[G[v][i]]--;
			if (degree[G[v][i]] == 0) degQ.push(G[v][i]);
		}
	}
	return L;
}


int main() {
	int v, e;

	while (cin >> v >> e) {
		Graph G(v);
		vector<int> degree(v, 0);
		Prio degreeQ;
		readGraph(G, degree, degreeQ, e); 
		list<int> L = topological(G, degree, degreeQ);
		writeOrder(L);
	}
}