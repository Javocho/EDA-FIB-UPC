#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef vector<vector<int>> Graph;
typedef pair<int, vector<int>> Path;

void readGraph(Graph& G, int e) {
	int v1, v2;
	for (int i = 0; i < e; i++) {
		cin >> v1 >> v2;
		G[v1].push_back(v2);
	}
}

void writeVertices(const vector<int>& V) {
	bool first = true;
	for (int w : V) {
		if (first) first = false;
		else cout << ' ';
		cout << w;
	}
}

void bfs(const Graph& G, vector<int>& partialSol) {
	queue<int> Q;
	Q.push(0);
	vector<bool> visited(G.size(), false);
	while (not Q.empty()) {
		int u = Q.front();
		Q.pop();
		visited[u] = true;
		partialSol.push_back(u);
		// cout << u << endl;
		if (u == G.size() - 1) return;
		for (int v : G[u]) {
			if (not visited[v]) Q.push(v);
		}
		partialSol.pop_back();
	}
}

int main() {
	int v,e;
	while (cin >> v >> e) {
		Graph G(v);
		readGraph(G, e);
		vector<int> sol(v);
		bfs(G, sol);
		writeVertices(sol);
	}
}