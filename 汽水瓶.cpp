#include<iostream>
#include<vector>
using namespace std;

int sss(int n,int sum) {
	if (n < 2)
		return sum;
	if (n == 2)
		return sum + 1;
	sum += n / 3;
	n = n / 3 + n % 3;
	return sss(n, sum);
}

int main9() {
	int n;
	vector<int>v;
	while (cin >> n) {
		if (n != 0)
			v.push_back(n);
		else
			break;
	}
	for (int i = 0; i < v.size(); ++i) {
		int sum = 0;
		cout << sss(v[i], sum) << endl;
	}
	system("pause");
	return 0;
}