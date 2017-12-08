#include <iostream>
#include <map>

using namespace std;

int main() {
	map<string, int> m;
	string name, action;
	while (cin >> name and cin >> action) {
		if (action == "enters") {
			if (m.find(name) != m.end()) { //está
				cout << name << " is already in the casino" << endl;
			}
			else { //no está
				m[name] = 0;
			}
		}
		else if (action == "leaves") {
			if (m.find(name) != m.end()) { //está
				cout << name << " has won " << m.find(name)->second << endl;
				m.erase(name);
			}
			else { //no está
				cout << name << " is not in the casino" << endl;
			}
		}
		else if (action == "wins") {
			int number;
			cin >> number;
			if (m.find(name) != m.end()) { //está
				m.find(name)->second += number;
			}
			else { //no está
				cout << name << " is not in the casino" << endl;
			}
		}
	}
	cout << "----------" << endl;
	if (!m.empty()) {
		map<string,int>::iterator it;
		for (it = m.begin(); it != m.end(); ++it) {
			cout << it->first << " is winning " << it->second << endl;
		}
	}
	system("pause"); 
	return 0;
}
