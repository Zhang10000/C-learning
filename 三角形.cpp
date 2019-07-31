#include<iostream>
#include<string>
using namespace std;
string Add(string s, string y) {
	if (y.size() > s.size())
		swap(s, y);
	int g = 0;
	string a(s.size() - y.size(), '0');
	y = a + y;
	for (int i = s.size() - 1; i >= 0; i--) {
		int temp = s[i] - '0';
		s[i] = (s[i] + y[i] - 2 * '0' + g) % 10 + '0';
		g = (temp + y[i] - '0' + g) / 10;
	}
	if (g != 0)
		s = '1' + s;
	return s;
}
bool great(string s1, string s2) {
	int len1 = s1.size(), len2 = s2.size();
	if (len1 > len2) return true;
	else if (len1 < len2) return false;
	else return s1 > s2;
}
int main() {
	string a, b, c;
	while (cin >> a >> b >> c)
		if (great(Add(a, b), c) && great(Add(a, c), b) && great(Add(b, c), a)) cout << "Yes" << endl;
		else cout << "No" << endl;
}
