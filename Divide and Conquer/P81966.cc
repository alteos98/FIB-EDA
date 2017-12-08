#include <iostream>
#include <vector>

using namespace std;

int posicio(double x, const vector<double>& v, int esq, int dre) {
	if (dre < esq) {
		return -1;
	}
	else {
		int m = (esq+dre)/2;
		if (v[m] == x) {
			return m;
		}
		else {
			if (v[m] > x) {
				return posicio(x,v,esq,m-1);
			}
			else {
				return posicio(x,v,m+1,dre);
			}
		}
	}
}

int main () {
	int n;
	cin >> n;
	vector<double> v(n);
	for (int i=0; i<n; ++i) {
		cin >> v[i];
	}
	int x;
	cin >> x;
	x = posicio(x,v,0,n-1);
	cout << x << endl;
}
