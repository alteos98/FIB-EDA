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

void zeros_i_uns (vector<int>& v, int i, int uns, int n_uns, int zeros, int n_zeros) {
	if (i == v.size()) {
        escriure_vector(v);
    }
    else {
        v[i] = 0;
        if (zeros < n_zeros) zeros_i_uns(v, i+1, uns, n_uns, zeros+1, n_zeros);
        v[i] = 1;
        if (uns < n_uns) zeros_i_uns(v, i+1, uns+1, n_uns, zeros, n_zeros);
    }
}

int main() {
	int n, n_uns, n_zeros;
	cin >> n >> n_uns;
	vector<int> v(n, 0); //vector de tamny n i l'inicialitzem a 0
	n_zeros = n - n_uns;
	zeros_i_uns(v,0,0,n_uns,0,n_zeros);
}
