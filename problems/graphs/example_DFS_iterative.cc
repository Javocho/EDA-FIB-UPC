#include <iostream>
#include <vector>
#include <list>
#include <stack>

using namespace std;

typedef vector< vector<int> > graph;

list<int> DFS_ite (const graph& G) {
	int n = G.size();
	list<int> L;
	stack<int> S;
	vector<bool> vis(n, false);
	for (int u = 0; u < n; ++u) {
		S.push(u);
		while (not S.empty()) {
			int v = S.top(); S.pop();
			if (not vis[v]) {
				// cout << v << endl;
				vis[v] = true; L.push_back(v);
				// if (not L.empty()) cout << "proceso intermedio " << L.front() << endl;
				for (int w : G[v])
				{
					S.push(w); 
					cout << w << endl;
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
  
	list<int> l = DFS_ite(G);
	for (auto it = l.begin(); it != l.end(); it++) {
		cout << *it << endl;
	}
}