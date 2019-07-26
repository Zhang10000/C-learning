#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int fCost(string A, string B) {
	int n = A.size(), m = B.size();
	vector< vector<int> > dp(n + 1, vector<int>(m + 1, 0));
	for (int i = 1; i <= m; ++i) dp[0][i] = i;
	for (int i = 1; i <= n; ++i) dp[i][0] = i;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j) {
			int case1 = dp[i - 1][j] + 1, case2 = dp[i][j - 1] + 1, case3 = dp[i - 1][j - 1];
			if (A[i - 1] != B[j - 1]) case3 += 1;
			dp[i][j] = min(min(case1, case2), case3);
		}
	return dp[n][m];
}
int main() {
	string a, b;
	while (cin >> a >> b) cout << fCost(a, b) << endl;
	return 0;
}


