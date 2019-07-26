#include<iostream>
#include<string>
using namespace std;
int main767676() {
	string s;
	while (cin >> s) {
		int min = s.size();
		int a[256] = { 0 };
		for (int i = 0; i < s.size(); ++i)
			a[s[i]]++;
		for (int i = 0; i < 256; ++i)
			if (a[i] == 1)
				min = min > s.find(i) ? s.find(i) : min;
		if (min == s.size())
			cout << -1 << endl;
		else
			cout << s[min] << endl;
	}
	return 0;
}