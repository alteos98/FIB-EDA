#include <iostream>
#include <queue>

using namespace std;

int main() {
	cout.setf(ios::fixed);
    cout.precision(4);
	priority_queue<int, vector<int>, greater<int> > q;
	string instruction;
	double suma = 0;
	double contador = 0;
	int max;
	while (cin >> instruction) {
		if (instruction == "number") {
			int number;
			cin >> number;
			q.push(number);
			++contador;
			suma += number;
			if (contador == 1) max = number;
			else if (number > max) max = number;
		}
		if (instruction == "delete") {
			if (!q.empty()) {
				suma -= q.top();
				--contador;
				q.pop();
			}
		}
		if (q.empty()) {
			cout << "no elements" << endl;
		}
		else {
			double mitjana = suma / contador;
			cout << "minimum: " << q.top() << ", ";
			cout << "maximum: " << max << ", ";
			cout << "average: " << mitjana << endl;
		}
	}
}
