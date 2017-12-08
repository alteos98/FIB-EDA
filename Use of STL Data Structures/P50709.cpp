#include <iostream>
#include <list>

using namespace std;

int main() {
	list<int> l;
	list<int>::iterator it = l.begin();
	list<int>::iterator it_max = l.end();
	char action;
	int n;
	while (cin >> action) {
		if (action == 'S') { //guarda una copia de un número n en la lista
			cin >> n;
			if (!l.empty() and n > *it_max) {
				it_max = l.end();
			}
			l.push_back(n);
		}
		else if (action == 'A') {
			if (!l.empty()) {
				cout << *it_max << endl;
			}
			else {
				cout << "error!" << endl;
			}
		}
		else if (action == 'R') {
			if (it_max != l.end()) {
				it_max = l.erase(it_max);
			}
			else {
				cout << "error!" << endl;
			}
		}
		else if (action == 'I') {
			cin >> n;
			if (it_max != l.end()) {
				*it_max += n;
			}
			else {
				cout << "error!" << endl;
			}
		}
		else if (action == 'D') {
			cin >> n;
			if (it_max != l.end()) {
				*it_max -= n;
			}
			else {
				cout << "error!" << endl;
			}
		}
	}
}
