#include <iostream>
#include <vector>

using namespace std;

vector<bool> mp; //marquem les permutacions

void llegir_vector(vector<string>& v) {
	for (int i=0; i < v.size(); ++i) {
		cin >> v[i];
	}
}

void escriure_permutacio (vector<string>& v) {
	if (v.size() > 0) {
		cout << "(" << v[0];
		for (int i=1; i < v.size(); ++i) {
			cout << "," << v[i];
		}
		cout << ")" << endl;
	}
}

void calcul_permutacions (vector<string>& v, vector<string>& paraules, int i) {
	if (i == v.size()) {
        escriure_permutacio(v);
    }
    else {
    	for (int j=0; j < v.size(); ++j) {
    		if (not mp[j]) {
    			string aux = v[i];
    			v[i] = paraules[j];
    			mp[j] = true;
    			calcul_permutacions(v,paraules,i+1);
    			mp[j] = false;
    			v[i] = aux;
			}
    		
		}
    }
}

int main() {
	int n;
	cin >> n;
	vector<string> v(n);
	vector<string> paraules(n);
	llegir_vector(paraules);
	mp = vector<bool> (n, false);
	if (n > 1) calcul_permutacions(v,paraules,0);
	else escriure_permutacio(paraules);
}
