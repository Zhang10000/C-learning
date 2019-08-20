#include<string>
#include<iostream>
using namespace std;
int main() {
	string s;
	while (cin >> s) {
		for (int i = 1; i < s.size() - 1; i++) {
			if (s[i] == '_') {
				s.erase(s.find('_'),1);
				s[i] = s[i] - 'a' + 'A';
			}
		}
		cout << s << endl;
	}
	return 0;
}