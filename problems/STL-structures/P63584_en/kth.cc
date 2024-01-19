#include <iostream> 
#include <vector>
#include <map>

using  namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;

int k_esim(int k, const VVI& V) {
	map<int, int> firstElements;
	for (int i = 0; i < V.size(); i++) {
		if (!V[i].empty()) firstElements[V[i][0]] = i;
	}

	pair<int, int> result;
	vector<int> visited(V.size(), 1);
	while (k > 0) {
		if (firstElements.empty()) k = 0;
		auto it = firstElements.begin();
		result.first = it->first;
		result.second = it->second;
		firstElements.erase(it);
		if (visited[result.second] < V[result.second].size()) { //para que no siga copiando vector fuera de su tamaño
			firstElements[V[result.second][visited[result.second]]] = result.second;
			visited[result.second]++;
		}
		k--;
	}
	return result.first;
}