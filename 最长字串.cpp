#include<iostream>
#include<string>
using namespace std;

void Max_zc(string s, string y) {
	int max = 0;
	for (int i = 0; i < s.size(); ++i)
		for (int j = 1; j + i < s.size(); ++j)
			if (y.find(s.substr(i, j)) != -1) max = max > j ? max : j;
	cout << max << endl;
}

int main111111111111() {
	string s1, s2;
	while (cin >> s1 >> s2) {
		if (s1.size() > s2.size()) Max_zc(s2, s1);
		else Max_zc(s1, s2);
	}
	system("pause");
	return 0;
}