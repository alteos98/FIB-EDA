
#include <iostream>
#include <vector>

using namespace std;

vector<bool> m_consonants; //per marcar les consonants ja usades
vector<bool> m_vocals; //per marcar les vocales ja usades

void llegir_consonants_vocals (vector<char>& consonants, vector<char>& vocals) {
	for (int i=0; i< consonants.size(); ++i) {
		cin >> consonants[i];
	}
	for (int i=0; i< vocals.size(); ++i) {
		cin >> vocals[i];
	}
}

void escriu_permutacio (vector<char>& resultat) {
	for (int i=0; i < resultat.size(); ++i) {
		cout << resultat[i];
	}
	cout << endl;
}

int permutacions (int i, int n, vector<char>& consonants, vector<char>& vocals, vector<char>& resultat) {
	if (i == n) {
		escriu_permutacio(resultat);
	}
	else {
		for (int j=0; j < n; ++j) {
			if (!m_consonants[j]) {
				resultat[2*i] = consonants[j];
				m_consonants[j] = true;
				for (int k=0; k < n; ++k) {
					if (!m_vocals[k]) {
						resultat[2*i+1] = vocals[k];
						m_vocals[k] = true;
						permutacions(i+1, n, consonants, vocals, resultat);
						m_vocals[k] = false;
					}
				}
				m_consonants[j] = false;
			}
		}
	}
}

int main() {
	int n;
	cin >> n;
	vector<char> consonants (n);
	vector<char> vocals (n);
	llegir_consonants_vocals(consonants, vocals);
	vector<char> resultat (2*n);
	m_consonants = vector<bool> (n, false);
	m_vocals = vector<bool> (n, false);
	permutacions(0, n, consonants, vocals, resultat);
}
