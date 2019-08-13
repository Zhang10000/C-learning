#include<string>
#include<vector>
#include<iostream>
using namespace std;
int Find(vector<string>&v, string s) {
	if (v.empty())
		return -1;
	for (int i = 0; i < v.size(); ++i)
		if (v[i] == s)
			return i;
	return -1;
}
void Min_child(vector<string>&v) {
	vector<string>s;
	vector<int>count;
	for (int i = 0; i < v.size(); i++) {
		if (Find(s, v[i]) == -1) {
			s.push_back(v[i]);
			count.push_back(1);
		}
	}
	for (int i = 0; i < v.size(); i++) {
		string a = v[i];
		int sum = 0;
		while (i < v.size() && a == v[i]) {
			sum++;
			i++;
		}
		count[Find(s, a)] = sum > count[Find(s, a)] ? sum : count[Find(s, a)];
	}
	int sum = 0;
	for (int i = 0; i < count.size(); ++i)
		sum = sum > count[i] ? sum : count[i];
		//sum += count[i];
	cout << sum << endl;
}
//int main() {
//	int n;
//	while (cin >> n) {
//		string s;
//		vector<string>v;
//		while (n--) {
//			cin >> s >> s;
//			v.push_back(s);
//		}
//		Min_child(v);
//	}
//	return 0;
//}