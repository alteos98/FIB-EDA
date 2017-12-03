#include <iostream>
#include <vector>

using namespace std;

vector<int> t; //les reines

vector<int> mc; //marquem si hi ha reina a la columna mc[k]
vector<int> md1; //marquem si hi ha reina a la diagonal 1, i + j = k, md1[k]
vector<int> md2; //marquem si hi ha reina a la diagonal 2, n + i - j - 1 = k, md2[k]

void escriu_tauler () {
	for (int i=0; i < t.size(); ++i) {
		for (int j=0; j < t.size(); ++j) {
			if (t[i] == j) cout << "Q";
			else cout << ".";
		}
		cout << endl;
	}
}

int calcul_diagonal1 (int i, int j) {
	return i + j;
}

int calcul_diagonal2 (int i, int j, int n) {
	return n + i - j - 1;
}

int reines (int i, int n, bool& trobat) {
	if (i == n) {
		escriu_tauler();
		trobat = true;
	}
	else {
		int j = 0;
		while (j < n and !trobat) {
			if (mc[j] == 0 and md1[calcul_diagonal1(i,j)] == 0 and md2[calcul_diagonal2(i,j,n)] == 0) {
				t[i] = j;
				mc[j] = 1;
				md1[calcul_diagonal1(i,j)] = 1;
				md2[calcul_diagonal2(i,j,n)] = 1;
				reines(i+1,n,trobat);
				mc[j] = 0;
				md1[calcul_diagonal1(i,j)] = 0;
				md2[calcul_diagonal2(i,j,n)] = 0;
			}
			++j;
		}
	}
}

int main() {
	int n;
	cin >> n;
	t = vector<int> (n, -1);
	mc = vector<int> (n, 0);
	md1 = vector<int> (2*n-1, 0);
	md2 = vector<int> (2*n-1, 0);
	bool trobat = false;
	reines(0,n,trobat);
	if (not trobat) cout << "NO SOLUTION" << endl;
}
