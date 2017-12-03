#include <iostream>
#include <vector>

using namespace std;

vector<int> t; //les reines

vector<int> mc; //marquem si hi ha reina a la columna mc[k]
vector<int> md1; //marquem si hi ha reina a la diagonal 1, i + j = k, md1[k]
vector<int> md2; //marquem si hi ha reina a la diagonal 2, n + i - j - 1 = k, md2[k]

int calcul_diagonal1 (int i, int j) {
	return i + j;
}

int calcul_diagonal2 (int i, int j, int n) {
	return n + i - j - 1;
}

int reines (int i, int n) {
	if (i == n) {
		return 1;
	}
	else {
		int res = 0;
		for (int j=0; j < n; ++j) {
			if (mc[j] == 0 and md1[calcul_diagonal1(i,j)] == 0 and md2[calcul_diagonal2(i,j,n)] == 0) {
				t[i] = j;
				mc[j] = 1;
				md1[calcul_diagonal1(i,j)] = 1;
				md2[calcul_diagonal2(i,j,n)] = 1;
				res += reines(i+1,n);
				mc[j] = 0;
				md1[calcul_diagonal1(i,j)] = 0;
				md2[calcul_diagonal2(i,j,n)] = 0;
			}
		}
		return res;
	}
}

int main() {
	int n;
	cin >> n;
	t = vector<int> (n, -1);
	mc = vector<int> (n, 0);
	md1 = vector<int> (2*n-1, 0);
	md2 = vector<int> (2*n-1, 0);
	cout << reines(0,n) << endl;
}
