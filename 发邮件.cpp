#/*include<iostream>
using namespace std;
int main() {
	long long a;
	long long sum[21] = { 0 };
	sum[1] = 0;
	sum[2] = 1;
	for (int i = 3; i < 21; ++i) {
		sum[i] = (i - 1)*(sum[i - 1] + sum[i - 2]);
	}
	while (cin >> a) {
		cout << sum[a] << endl;
	}
	return 0;
}*/