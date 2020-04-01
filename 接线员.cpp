#include<iostream>
#include<vector>
#include<string>
using namespace std;

vector<int> to_num(string s) {
	vector<int>tmp;
	int sum = 0;
	for (int i = 0; s[i] != '\0'; i++) {
		if (s[i] == ',') {
			tmp.push_back(sum);
			sum = 0;
			i++;
		}
		sum = sum * 10 + s[i] - '0';
	}
	tmp.push_back(sum);
	return tmp;
}
bool find(vector<int>& V, int k) {
	for (auto e : V)
		if (e > k || e == k)
			return true;
	return false;
}
int main() {
	int res;
	while (cin >> res) {
		vector<vector<int>> S;
		string s;
		getchar();
		while (res) {
			getline(cin, s);
			S.push_back(to_num(s));
			res--;
		}
		int a[1024] = { 0 };
		int max = 0;
		for (auto e : S) {
			for (int i = e[0]; i < e[1]; i++) {
				a[i]++;
				max = max > a[i] ? max : a[i];
			}
		}
		cout << max << endl;
	}
	return 0;
}
