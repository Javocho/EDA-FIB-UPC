#include <iostream>
#include <vector>
#include <list>
#include <queue>

using namespace std;

typedef vector< vector<int> > graph;

list<int> BFS(const graph& G) {
	int n = G.size();
	list<int> L;
	queue<int> Q;
	vector<bool> enc(n, false);
	for (int u = 0; u < n; ++u) {
		if (not enc[u]) {
			Q.push(u);
			enc[u] = true;
			while (not Q.empty()) {
				int v = Q.front();
				Q.pop();
				L.push_back(v);
				for (int w : G[v]) {
					if (not enc[w]) {
						Q.push(w);
						enc[w] = true;
					}
				}
			}
		}
	}
	return L;
}

int main() {
	graph G = {{1, 2, 3},   // Vertex 0 is connected to vertices 2, 3, 4
               {0, 4, 5},   // Vertex 1 is connected to vertices 2, 3, 4
               {0, 6},      // Vertex 2 is connected to vertices 1, 7
               {0, 7},      // Vertex 3 is connected to vertices 1, 8
               {1},         // Vertex 4 is connected to vertex 2
               {1},         // Vertex 5 is connected to vertex 2
               {2},         // Vertex 6 is connected to vertex 3
               {3},         // Vertex 7 is connected to vertex 4
    };
  
	list<int> l = BFS(G);
	for (auto it = l.begin(); it != l.end(); it++) {
		cout << *it << endl;
	}
}