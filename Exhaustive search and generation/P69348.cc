#include <iostream>
#include <vector>

using namespace std;

vector<bool> mp; //marquem les permutacions

void escriure_permutacio (vector<int>& v) {
	if (v.size() > 0) {
		cout << "(" << v[0];
		for (int i=1; i < v.size(); ++i) {
			cout << "," << v[i];
		}
		cout << ")" << endl;
	}
}

void calcul_permutacions (vector<int>& v, int i) {
	if (i == v.size()) {
        escriure_permutacio(v);
    }
    else {
    	for (int j=0; j < v.size(); ++j) {
    		if (not mp[j]) {
    			int aux = v[i];
    			v[i] = j + 1;
    			mp[j] = true;
    			calcul_permutacions(v,i+1);
    			mp[j] = false;
    			v[i] = aux;
			}
    		
		}
    }
}

int main() {
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i=0; i < v.size(); ++i) {
		v[i] = i + 1;
	}
	mp = vector<bool> (n, false);
	if (n > 1) calcul_permutacions(v,0);
	else escriure_permutacio(v);
}
