#include<string>
#include<cmath>
#include<iostream>
using namespace std;
int main1212() {
	int a, b;
	string s, y;
	while (cin >> s >> y >> a >> b) {
		long sumer = 0;
		s.append(b - s.size(), 'a');
		y.append(b - y.size(), 'z' + 1);
		for (int i = a; i <= b; ++i) {
			for (int j = 0; j < i; ++j) {
				int c = y[j] - s[j];
				sumer += c * pow(26, i - 1 - j);
			}
		}
		cout << (sumer - 1) % 1000007 << endl;
	}
	return 0;
}