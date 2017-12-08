#include <iostream>
#include <vector>

using namespace std;

void pow (vector< vector<int> >& M, int n, int m) {
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
            pow(M, n/2, m);
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
                M[0][0] = (r[0][0] + r[0][1])%m;
	            M[0][1] = (r[0][0])%m;
	            M[1][0] = (r[1][0] + r[1][1])%m;
	            M[1][1] = (r[1][0])%m;
            }
        }
}

int fibonacci(int n, int m) {
	if (n == 0) return 0;
	else {
		vector< vector<int> > M (2, vector<int>(2));
		M[0][0] = M[0][1] = M[1][0] = 1;
	    M[1][1] = 0;
	    pow(M,n,m);
	    return M[0][1];
	}
}

int main() {
    int n, m;
    while (cin >> n >> m) {
        cout << fibonacci(n,m) << endl;
    }
}
