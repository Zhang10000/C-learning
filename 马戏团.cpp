#include<iostream>
#include<vector>
using namespace std;
int main() {
	int n;
	while (cin >> n) {
		int a;
		vector<int>weight;
		vector<int>high;
		vector<int>sum(n, 1);
		for (int i = 0; i < n; i++) {
			cin >> a >> a;
			weight.push_back(a);
			cin >> a;
			high.push_back(a);
		}
		while(n){
			for (int i = 1; i < n; i++) {
				if (weight[i] < weight[i - 1]) {
					swap(weight[i], weight[i - 1]);
					swap(high[i], high[i - 1]);
				}
			}
			n--;
		}
		for (int i = 1; i < high.size(); i++) {
			for (int j = 0; j < i; j++) {
				if ((high[i] >= high[j] && weight[i] > weight[j]) || (high[i] == high[j] && weight[i] == weight[j]))
					sum[i] = sum[i] > sum[j] + 1 ? sum[i] : sum[j] + 1;
			}
		}
		int max = 0;
		for (int i = 0; i < high.size(); i++)
			max = max > sum[i] ? max : sum[i];
		cout << max << endl;
	}
	return 0;
}