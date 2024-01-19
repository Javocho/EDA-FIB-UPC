#include <iostream>
#include <vector>
#include <list>
#include <limits.h>
#include <queue>

using namespace std;

typedef pair<int, int> arcW;
typedef vector<vector<arcW>> Graph;

void readGraph(Graph &G, int m) {
	int v1, v2, w;
	for (int i = 0; i < m; i++) {
		cin >> v1 >> v2 >> w;
		G[v1].push_back({w, v2});
	}
}


int dijkstra(const Graph &G) {
	int n = G.size();
	vector<int> dist(n, INT_MAX);
	vector<bool> S(n, false);
	int dist_path = 0;
	dist[0] = 0;
	priority_queue<arcW, vector<arcW>, greater<arcW>> Q;
	Q.push({0,0});
	while (not Q.empty()) {
		int u = Q.top().second;
		if (not S[u]) {
			S[u] = true;
			dist_path += dist[u];
			if (u == G.size() -1) return dist_path;
			Q.pop();
			for (int i = 0; i < G[u].size(); i++) {
				int v = G[u][i].second;
				int w = G[u][i].first;
				if (dist[v] > dist[u] + w) {
					dist[v] = dist[u] + w;
					Q.push({dist[v], v});
				}
			}
		}
	}
	return dist_path;
}

int main() {
	int n, m;
	while (cin >> n >> m) {
		Graph G(n);
		readGraph(G, m);
		cout << dijkstra(G) << endl;
	}
}