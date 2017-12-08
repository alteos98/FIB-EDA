#include <iostream>
#include <vector>

using namespace std;

int pos(double x, const vector<double>& v, int esq, int dre) {
	if (esq > dre) return -1;
	int m = (esq+dre)/2;
	if (v[m] > x) return pos(x,v,esq,m-1);
	if (v[m] < x) return pos(x,v,m+1,dre);
	if (m-1 >= 0) { //per si tractem l'element 0
		int aux = pos(x,v,esq,m-1);
		if (aux != -1) return aux;
	}
	return m;
}

int first_occurrence(double x, const vector<double>& v) {
	//Pre: vector en ordre decreixent
	return pos(x,v,0,v.size()-1);
}

int main () {
	int n;
	cin >> n;
	vector<double> v(n);
	for (int i=0; i<n; ++i) {
		cin >> v[i];
	}
	double x;
	cin >> x;
	x = first_occurrence(x,v);
	cout << x << endl;
}
