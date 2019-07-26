#include<iostream>
#include<vector>
using namespace std;
int main020202() {
	int n, s, t;
	vector<int>c;
	while (cin >> n >> s) {
		vector<int>v;
		while (n--) {
			cin >> t;
			v.push_back(t);
		}
		for (int i = 0; i < v.size(); ++i)
			if (s >= v[i])
 				s += v[i];
			else
				for (int j = v[i]; j > 0; j--)
					if (s % j == 0 && v[i] % j == 0) {
						s += j;
						break;
					}
						
		c.push_back(s);
	}
	for (int i = 0; i < c.size(); ++i)
		cout << c[i] << ' ' << endl;
	return 0;
}