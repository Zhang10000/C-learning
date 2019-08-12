#include<iostream>
#include<string>
using namespace std;
int main212() {
	string s;
	while (getline(cin, s)) {
		string sn;
		cin >> sn;
		for (int i = 0; i < s.size(); ++i) {
			string a;
			++i;
			for (; i < s.size(); ++i) {
				if (s[i] == ',' && (!a.empty()) && a[0] != '\"')
					break;
				if (s[i] == '\"' && (!a.empty()) && a[0] == '\"') {
					a.erase(0, 1);
						break;
				}
				a += s[i];
			}
			if (a == sn)
				cout << "Ignore" << endl;
			if (i == s.size() && a != sn)
				cout << "Important!" << endl;
		}
	}
	return 0;
}