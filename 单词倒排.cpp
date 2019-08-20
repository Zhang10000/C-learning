#include<string>
#include<iostream>
using namespace std;
int main() {
	string a;
	while (getline(cin, a)) {
		string s = {};
		for (int i = a.size() - 1; i >= 1; i--) {
			if (a[i] == ' ' && a[i - 1] != ' ') {
				for (int j = i + 1; j < a.size(); ++j) 
					if (a[j] != ' ') {
						cout << a[j];
						s = ' ';
					}
				a.erase(i);
				cout << s;
				s.clear();
			}
		}
		for (int i = 0; i < a.size(); ++i) if (a[i] != ' ') cout << a[i];
		cout << ' ' << endl;
	}
	return 0;
}