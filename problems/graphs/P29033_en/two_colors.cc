#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int>> Graf;

void insertNodes(Graf& G, int e) {
    int e1, e2;

    for (int i = 0; i < e; i++) {
        cin >> e1 >> e2;
        G[e1].push_back(e2);
        G[e2].push_back(e1);
    }
}

bool dfsColored(const Graf& G, vector<bool>& visited, vector<int>& color, int& last_color, int i) {
    if (!visited[i]) {
        visited[i] = true;
        color[i] = !last_color;
        last_color = !last_color;
        for (int v : G[i]) {
            if (not dfsColored(G, visited, color, last_color, v))
                return false;  // Return false if any adjacent node is not properly colored
        }
    } else {
        return color[i] != last_color;
    }
    return true;
}

bool dfsColored(const Graf& G) {
    vector<bool> visited(G.size(), false);
    vector<int> color(G.size());
    int last_color = 0;
    bool col;
    for (int i = 0; i < G.size(); i++) {
        if (not visited[i])
            col = dfsColored(G, visited, color, last_color, i);
        if (not col) return false;
    }
    return true;
}

int main() {
	int n, e;
	while (cin >> n >> e) {
		Graf G(n);
		insertNodes(G, e);
	// Graf G = {{1,2}, {0,2}, {0,1},{}};
		if (!dfsColored(G)) cout << "no" << endl;
		else cout << "yes" << endl;
	}
}


