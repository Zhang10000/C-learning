#include<iostream>
#include<string>
using namespace std;
int main000() {
	string s,y;
	while (cin >> s) {
		y.assign(s.rbegin(), s.rend());
		cout << y << endl;
	}
	return 0;
}