#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int> > Graf;

vector<int> marcats;

void crear_vector (vector<int>& v) {
	for (int i=0; i < v.size(); ++i) v[i] = i;
}

void llegir_parells (int m, Graf& parells) {
	int primer, segon;
	for (int i=0; i < m; ++i) {
		cin >> primer >> segon;
		parells[primer].push_back(segon);
		++marcats[segon];
	}
}

void escriure_vector (vector<int>& v) {
	for (int i=0; i < v.size(); ++i) {
		if (i == 0) cout << v[i];
		else cout << " " << v[i];
	}
	cout << endl;
}

void ordenacions_topologiques (int i, int n, vector<int>& v, Graf& parells) {
	if (i == n) {
		escriure_vector(v);
	}
	else {
		for (int j=0; j < n; ++j) {
			if (marcats[j] == false) {
				v[i] = j;
				--marcats[j];
				for (int k=0; k < parells[j].size(); ++k) {
					--marcats[parells[j][k]];
				}
				ordenacions_topologiques(i+1, n, v, parells);
				++marcats[j];
				for (int k=0; k < parells[j].size(); ++k) {
					++marcats[parells[j][k]];
				}
			}
		}
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	marcats = vector<int> (n, 0);
	Graf parells (n); //on tindrem les preferencies
	llegir_parells(m, parells);
	vector<int> v (n);
	crear_vector(v);
	ordenacions_topologiques(0, n, v, parells);
}
