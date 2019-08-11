#include <iostream>
#include <string>
using namespace std;
int main21() {
	int n;
	while (cin >> n) {
		cin.get();
		string name;
		for (int i = 0; i < n; i++) {
			getline(cin, name);
			if (i != n - 1) {
				if (name.find(',') != -1 || name.find(' ') != -1)
					cout << '\"' << name << '\"' << ',' << ' ';
				else
					cout << name << ',' << ' ';
			}
			else {
				if (name.find(',') != -1 || name.find(' ') != -1)
					cout << '\"' << name << '\"' << endl;
				else
					cout << name << endl;
			}
		}
	}
	return 0;
}