#include<string>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;
int main(){
	string a, b;
	while (cin >> a >> b) {
		vector<vector<int>>v(a.size() + 1, vector<int>(b.size() + 1, 0));
		for (int i = 0; i < a.size(); i++) {
			for (int j = 0; j < b.size(); ++j) {
				if (a[i] == b[j])
					v[i + 1][j + 1] = v[i][j] + 1;
				else
					v[i + 1][j + 1] = max(v[i][j + 1], v[i + 1][j]);
			}
		}
		cout << v[a.size()][b.size()] << endl;
	}
	return 0;
}