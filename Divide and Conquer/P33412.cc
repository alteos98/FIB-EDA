#include <iostream>
#include <vector>

using namespace std;

bool hi_es(double x, const vector<double>& v, int esq, int dre) {
	if (esq > dre) return false;
	int m = (esq+dre)/2;
	int a;
	if (v[m] > x /*and m+1 <= v.size()-1 and v[m+1] != x*/) {
		a = m;
		while (a < v.size()-1 or v[a] <= v[a+1]) {
        	++a;
		}
		if (v[a+1] == x) return true;
		return hi_es(x,v,esq,m-1);
    }
	if (v[m] < x and (m-1) >= 0 and v[m-1] != x) {
		a = m;
		while (a > 0 or v[a-1] <= v[a]) {
        	--a;
		}
		if (v[a-1] == x) return true;
        return hi_es(x,v,m+1,dre);
    }
	return true;
}

bool resistant_search(double x, const vector<double>& v) {
	//Pre: vector en ordre decreixent
	return hi_es(x,v,0,v.size()-1);
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
    bool b;
	b = resistant_search(x,v);
    if (b) cout << "true" << endl;
    else cout << "false" << endl;
}
