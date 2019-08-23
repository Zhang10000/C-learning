#include<vector>
#include<iostream>
using namespace std;
long long prod(vector<int>&product, int n, long long pro, int k, int d) {
	if (k == 0)
		return pro;
	int max = INT32_MIN;
	int m = 0;
	product[n] = INT32_MIN;
	int right = n - d > 0 ? n - d : 0;
	int left = n + d < product.size() ? n + d : product.size();
	for (int i = right; i < left; i++) {
		if (product[i] > max) {
			max = product[i];
			m = i;
		}
	}
	prod(product, m, pro *= max, --k, d);
}
int main() {
	int n;
	while (cin >> n) {
		int num, k, m, d, max = INT32_MIN;
		vector<int>product;
		for (int i = 0; i < n; i++) {
			cin >> num;
			if (num > max) {
				max = num;
				m = i;
			}
			product.push_back(num);
		}
		cin >> k >> d;
		cout << prod(product, m, max, k - 1, d) << endl;
	}
	return 0;
}