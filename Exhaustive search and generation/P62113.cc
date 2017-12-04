#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void llegir (vector<int>& monedes) {
	for (int i=0; i < monedes.size(); ++i){
		cin >> monedes[i];
	}
}

void escriu_combinacio (int x, int i, vector<int>& resultat) {
	cout << x << " = ";
	bool first = true;
	for (int j=0; j < i; ++j) {
		if (resultat[j] != 0) {
			if (first) {
				first = false;
				cout << resultat[j];
				if (j%2 != 0) cout << "p";
			}
			else {
				cout << " + " << resultat[j];
				if (j%2 != 0) cout << "p";
			}
		}
	}
	cout << endl;
}

void canvi (int i, int suma, int x, vector<int>& monedes, vector<int>& resultat) {
	if (x == suma) {
		escriu_combinacio(x, i, resultat);
	}
	else if (i < resultat.size()) {
		if (suma < x) {
			int aux = resultat[i];
			resultat[i] = monedes[i/2];
			suma += monedes[i/2];
			canvi(i+1, suma, x, monedes, resultat);
			suma -= monedes[i/2];
			resultat[i] = aux;
			canvi(i+1, suma, x, monedes, resultat);
		}
	}
}

int main() {
	int x, n;
	while (cin >> x >> n) {
		vector<int> monedes (n);
		llegir(monedes);
		sort(monedes.begin(), monedes.end());
		vector<int> resultat (2*n);
		canvi(0, 0, x, monedes, resultat);
		cout << "----------" << endl;
	}
}
