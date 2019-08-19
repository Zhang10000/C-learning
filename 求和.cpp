#include<iostream>
#include<vector>
using namespace std;
void zuhe(int n,vector<int>v, int m, int sub) {
	if (m == 0) {
		for (int i = 0; i < v.size(); i++)
			i == 0 ? cout << v[i] : cout << " " << v[i];
		cout << endl;
	}
	for (int i = sub; i < n && i < m; i++) {
		v.push_back(i);
		zuhe(n, v, m - i, i + 1);
		v.pop_back();
	}
}
//int main() {
//	int n,m;
//	while (cin >> n >> m){
//		vector<int>v;
//		zuhe(n, v, m, 1);
//	}
//	return 0;
//}