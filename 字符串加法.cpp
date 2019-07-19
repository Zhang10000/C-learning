#include<iostream>
#include<string>
using namespace std;
string hahaha(string s, string y) {
	int gggggggggg = 0;
	string a(s.size() - y.size(), '0');
	y = a + y;
	for (int i = s.size() - 1; i >= 0; i--) {
		int temp = s[i] - '0';
		s[i] = (s[i] + y[i] - 2 * '0' + gggggggggg) % 10 + '0';
		gggggggggg = (temp + y[i] - '0' + gggggggggg) / 10;
	}
	if (gggggggggg != 0)
		s = '1' + s;
	return s;
}

int main() {
	string s, y;
	while (cin >> s >> y) {
		if(s.size()>y.size())
			cout << hahaha(s, y) << endl;
		else
			cout << hahaha(y, s) << endl;
	}	
	system("pause");
	return 0;
}