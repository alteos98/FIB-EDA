#include <iostream>

using namespace std;

int posicio(vector<int>& v, int a, int left, int right) {
	
}

int main() {
	int n, cont=1;
	while (cin >> n) {
		vector<int> v(n);
		for (int i=0; i<n; ++i) cin >> v[i];
		int m;
		vector<int> a(m);
		for (int i=0; i<m; ++i) cin >> a[i];
		cout << "Sequence #" << cont << endl;
		for (int i=0; i<m; ++i) {
			int p = posicio();
			if (!= -1) cout << "fixed point for " << a[i] << ": " << p << endl;
			else cout << "no fixed point for " << a[i] << endl;
		}
		cout << endl;
		++cont;
	}
}
