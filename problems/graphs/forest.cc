#include <iostream>
#include <vector>

using namespace std;

typedef vector< vector<int > > Graph;

void insert_graf(Graph &g, int e) {
	int n1, n2;
	for (int i = 0; i < e; i++) {
		cin >>n1;
		cin >> n2;
		g[n1].push_back(n2);
		g[n2].push_back(n1);
	}
}

void connect(const Graph& g, vector<bool>& vis, int root, int i, bool &cicle) {
	if (not vis[i]) {
		vis[i] = true;
		for (int j = 0; j < g[i].size(); ++j) {
			if (g[i][j] != root) {
				connect(g, vis, i, g[i][j], cicle);
				if (cicle) return;
			}
		}
	}
	else cicle = true;
}

int dfs(const Graph& g) {
	int narbres = 0;
	vector<bool> vis(g.size(), false);
	for (int i = 0; i < g.size(); i++) {
		if (not vis[i]) {
			bool cicle = false;
			connect(g, vis, i, i, cicle);
			if (cicle) return -1;
			else narbres++;
		}
	}
	return narbres;
}

int main() {
	int v, e;
	while (cin >> v >> e) {
		Graph g(v, vector<int>());
		insert_graf(g, e);
		int narbres = dfs(g);
		if (narbres > -1) cout << narbres << endl;
		else cout << "no" << endl;
	}
}