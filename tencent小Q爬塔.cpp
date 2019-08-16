/*#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	int n;
	while (cin >> n) {
		vector<int>highs;
		int a;
		for (int i = 0; i < n; i++) {
			cin >> a;
			highs.push_back(a);
		}
		if (n >= 2) {
			vector<int>gt = { highs[0],highs[0] + highs[1] };
			vector<int>dp = { highs[0],highs[0] };
			for (int i = 2; i < n; ++i) {
				gt.push_back(min(dp[i - 1], gt[i - 1]) + highs[i]);
				dp.push_back(min(gt[i - 1], gt[i - 2]));
			}
			cout << min(dp[n - 1], gt[n - 1]) << endl;
		}
		else {
			cout << highs[0] << endl;
		}
	}
	return 0;
}*/