#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool comp(pair<int, string> p1, pair<int, string> p2){
  if(p1.first > p2.first) return true;
  else if(p1.first < p2.first) return false;
  else{
    //p1.first == p2.first
    if(p1.second >= p2.second) return false;
    else return true;
  }
}

int main() {
	map<string, pair<bool, int> > m; //nom,conectat o no,elo
	map<string, pair<bool, int> >::iterator it;
	string instruction;
	while (cin >> instruction) {
		if (instruction == "LOGIN") {
			string nom;
			cin >> nom;
			it = m.find(nom);
			if (it != m.end()) { //s'havia conectat prèviament
				pair<bool,int> p = it->second;
				if (p.first == 0) { //no está conectat
					int elo = p.second;
					p = make_pair(1,elo);
					m[nom] = p;
				}
			}
			else { //no s'havia conectat abans encara
				m[nom] = make_pair(1,1200);
			}
		}
		if (instruction == "LOGOUT") {
			string nom;
			cin >> nom;
			it = m.find(nom);
			if (it != m.end()) { //s'havia conectat prèviament
				pair<bool,int> p = it->second;
				if (p.first == 1) { //está conectat
					int elo = p.second;
					p = make_pair(0,elo);
					m[nom] = p;
				}
			}
		}
		if (instruction == "PLAY") {
			map<string, pair<bool, int> >::iterator it2;
			string nom1, nom2;
			cin >> nom1 >> nom2;
			it = m.find(nom1);
			it2 = m.find(nom2);
			if (it != m.end() and it2 != m.end()) { //jugador1 i 2 estan
				pair<bool,int> p1 = it->second;
				pair<bool,int> p2 = it2->second;
				if (p1.first == 1 and p2.first == 1) { //estan conectat
					int elo = p1.second;
					p1 = make_pair(1,elo+10);
					m[nom1] = p1;
					elo = p2.second;
					if (elo >= 1210) {
						p2 = make_pair(1,elo-10);
						m[nom2] = p2;
					}
				}
				else {
					cout << "jugador(s) no connectat(s)" << endl;
				}
			}
			else {
				cout << "jugador(s) no connectat(s)" << endl;
			}
		}
		if (instruction == "GET_ELO") {
			string nom;
			cin >> nom;
			it = m.find(nom);
			if (it != m.end()) {
				pair<bool,int> p = it->second;
				cout << nom << " " << p.second << endl;
			}
		}
	}
	//rànking final
	cout << endl;
	cout << "RANKING" << endl;
	vector<pair<int,string> > v (m.size());
	it = m.begin();
	int i = 0;
	while (it != m.end()) {
		v[i].first = it->second.second;
		v[i].second = it->first;
		++i;
		++it;
	}
	sort(v.begin(), v.end(), comp);
	//sacar vector
	for (int i=0; i < v.size(); ++i) {
		cout << v[i].second << " " << v[i].first << endl;
	}
}
