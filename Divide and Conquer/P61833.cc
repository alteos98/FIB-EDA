#include <iostream>
#include <vector>

using namespace std;

void pow (vector< vector<int> >& M, vector< vector<int> >& MIni, int n, int m) {
    if (n == 0) {
        M[0][0] = M[1][1] = 1;
        M[0][1] = M[1][0] = 0;
    }
    else if (n == 1) {
		M[0][0] = (M[0][0])%m;
        M[0][1] = (M[0][1])%m;
        M[1][0] = (M[1][0])%m;
        M[1][1] = (M[1][1])%m;
	}
        else {
            pow(M, MIni, n/2, m);
            vector< vector<int> > r (2, vector<int>(2));
            r[0][0] = ((M[0][0] * M[0][0])%m + (M[0][1] * M[1][0])%m)%m;
            r[0][1] = ((M[0][0] * M[0][1])%m + (M[0][1] * M[1][1])%m)%m;
            r[1][0] = ((M[0][0] * M[1][0])%m + (M[1][0] * M[1][1])%m)%m;
            r[1][1] = ((M[1][0] * M[0][1])%m + (M[1][1] * M[1][1])%m)%m;
            if (n%2 == 0) {
            	M = r;
            }
            else {
                vector< vector<int> > s (2, vector<int>(2));
                s[0][0] = ((r[0][0] * MIni[0][0])%m + (r[0][1] * MIni[1][0])%m)%m;
                s[0][1] = ((r[0][0] * MIni[0][1])%m + (r[0][1] * MIni[1][1])%m)%m;
                s[1][0] = ((r[0][0] * MIni[1][0])%m + (r[1][0] * MIni[1][1])%m)%m;
                s[1][1] = ((r[1][0] * MIni[0][1])%m + (r[1][1] * MIni[1][1])%m)%m;
                M = s;
            }
        }
}

int main() {
    vector< vector<int> > M (2, vector<int>(2));
    while (cin >> M[0][0]) {
        cin >> M[0][1] >> M[1][0] >> M[1][1];
        vector< vector<int> > MIni (2, vector<int>(2));
        MIni = M;
        int n, m;
        cin >> n >> m;
        pow(M,MIni,n,m);
        cout << M[0][0] << " " << M[0][1] << endl;
        cout << M[1][0] << " " << M[1][1] << endl;
        cout << "----------" << endl;
    }
}
