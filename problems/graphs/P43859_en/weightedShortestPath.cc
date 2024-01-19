#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, double> ArcP;
typedef vector<vector<ArcP>> Graph;

void readGraph(Graph& G, int edges) {
	int weight, e1, e2;
	for (int i = 0; i < edges; i++) {
		cin >> weight >> e1 >> e2;
		G[e1].push_back(make_pair(e2, weight));
	}
}

double shortestPath(Graph& G, int x, int y, int edges) {
	vector<bool> visited(edges, false);
	vector<double> weights(edges, -1);
	priority_queue<ArcP, vector<ArcP>, greater<ArcP> > Q;
	
	Q.push(make_pair(x, 0));
	weights[x] = 0;

	while (not Q.empty()) {
		int actual = Q.top().first;
		Q.pop();

		if (not visited[actual]) {
			visited[actual] = true;

			for (int i = 0; i < G[actual].size(); i++) {
				int w = G[actual][i].second;
				int newnode = G[actual][i].first;

				if (weights[newnode] == -1 or weights[newnode] < weights[actual] + w) {
					weights[newnode] = weights[actual] + w;
					Q.push(make_pair(newnode, weights[newnode]));
				}
			}
		}
	}
	return weights[y];
}

int main() {
	int vertices, edges, x, y;
	while (cin >> vertices >> edges) {
		Graph G(edges);
		readGraph(G, edges);
		cin >> x >> y;
		int shortest = (int) shortestPath(G, x, y, edges);
		if (shortest == -1) cout << "no path from " << x << " to " << y << endl;
		else cout << shortest << endl;
	}
}