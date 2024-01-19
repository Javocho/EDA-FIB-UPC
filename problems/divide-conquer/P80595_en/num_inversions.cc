#include <iostream>
#include <vector>

using namespace std;

void merge(vector <int> &v, int left, int middle, int right, int &inversions) {

	int size = right-left;
	vector <int> merged(size+1);
	int i = left, j = middle+1, k = 0;
	while (i <= middle and j <= right){
		if (v[i] <= v[j])
			merged[k++] = v[i++];
		else{
			merged[k++] = v[j++];
			inversions += (middle + 1) - i; //How many elements remains in the left vector so the new element have to do that inversions to be sorted
		}
	}
	while (i <= middle)
		merged[k++] = v[i++];
	while (j <= right)
		merged[k++] = v[j++];
	for (i= 0; i <= size; ++i)
		v[left+i] = merged[i];
}


void inversions(vector<int>& v, int l, int r, int& ninversions) {
	if (l < r) {
		int m = (l+r)/2;
		inversions(v,l,m, ninversions);
		inversions(v,m+1,r, ninversions);
		merge(v, l, m, r, ninversions);
	}
}

int main() {
    int n;
    while(cin >> n) {
        vector<int> v(n);
		int ninversions = 0;
        for (int i = 0; i < n; ++i) cin >> v[i];
		inversions(v, 0, n-1, ninversions); //si emoieza en 0 es hasta n-1
		cout <<  ninversions << endl;
    }
}