#include<vector>
#include<iostream>
#include<string>
using namespace std;
template<class T>
int find(vector<T>s, T x) {
	for (int i = 0; i < s.size(); ++i)
		if (s[i] == x)
			return i;
	return -1;
}
int main() {
	vector<string>str;
	vector<int>lineno;
	vector<int>sum;
	string a;
	int b;
	while (cin >> a >> b) {
		if (find(str, a) != -1 && lineno[find(str, a)] == b) {
			sum[find(str, a)]++;
			continue;
		}
		string s;
		for (int i = a.size() - 1; i >= 0; --i) {
			if (a[i] == '\\') {
				for (i += 1; i < a.size(); ++i) 
					s.push_back(a[i]);
				break;
			}
			if (a.size() - i == 16 || i == 0) {
				for (; i < a.size(); ++i)
					s.push_back(a[i]);
				break;
			}
		}
		str.push_back(s);
		lineno.push_back(b);
		sum.push_back(1);
	}
	for (int i = 0; i < str.size(); ++i)
		cout << str[i] << ' ' << lineno[i] << ' ' << sum[i] << endl;
	return 0;
}