#include <iostream>
#include <vector>

using namespace std;

void escriure_vector (vector<int>& v) {
	for (int i=0; i < v.size(); ++i) {
		if (i==0) cout << v[i];
		else cout << " " << v[i];
	}
	cout << endl;
}

void zeros_i_uns (int vp, vector<int>& v) {
	if (vp > 1) {
		int i = v.size() - 1;
		bool canvi = false;
		while (!canvi and i >= 0) {
			if (v[i] == 0) {
				v[i] = 1;
				canvi = true;
			}
			else {
				v[i] = 0;
			}
			--i;
		}
		escriure_vector(v);
		zeros_i_uns(vp-1,v);
	}
}

int main() {
	int n;
	cin >> n;
	vector<int> v(n, 0); //vector de tamny n i l'inicialitzem a 0
	if (n > 0) escriure_vector(v);
	int vectors_possibles = 1; //tindrem el nombre de combinacions possibles
	for (int i=0; i < n; ++i) {
		vectors_possibles = vectors_possibles*2;
	}
	zeros_i_uns(vectors_possibles,v);
}
