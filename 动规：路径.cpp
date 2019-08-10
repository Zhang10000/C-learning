//#include<iostream>
//#include<vector>
//using namespace std;
//
//void find_ss(int n, int m) {
//	vector<vector<int> > a(n + 1, vector<int>(m + 1, 1));
//	for (int i = 1; i <= n; ++i) {
//		for (int j = 1; j <= m; ++j) {
//			a[i][j] = a[i - 1][j] + a[i][j - 1];
//		}
//	}
//	cout << a[n][m] << endl;
//}
//
//int main567789() {
//	int n, m;
//	cin >> n >> m;
//	find_ss(n, m);
//	return 0;
//}