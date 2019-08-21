#include<vector>
#include<string>
#include<algorithm>
#include<iostream>
using namespace std;
int main() {
	int n;
	while (cin >> n) {
		string a;
		vector<string>str;
		vector<vector<int>>sum;
		while (n) {
			cin >> a;
			str.push_back(a);
			sort(str.begin(), str.end());
			n--;
		}
		for (int i = 0; i < str.size(); ++i) {
			vector<int>v(26, 0);
			for (int j = 0; j < str[i].size(); ++j)
				v[str[i][j] - 'a']++;
			sum.push_back(v);
		}
		int x;
		int count = 0;
		string s;
		cin >> a >> x;
		vector<int>con(26, 0);
		for (int i = 0; i < a.size(); ++i)
			con[a[i] - 'a']++;
		for (int i = 0; i < sum.size(); i++)
			if (sum[i] == con && str[i] != a)
				count++;
		cout << count << endl;
		if (x > count || x == 0)
			continue;
		for (int i = 0; i < sum.size(); i++) {
			if (sum[i] == con && str[i] != a) {
				x--;
				if (x == 0) {
					s = str[i];
					break;
				}
			}
		}
		cout << s << endl;
	}
}