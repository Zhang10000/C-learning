#include<iostream>
#include<string>
#include<vector>
using namespace std;

int ssss(int & n) {
	vector<int>v(2 * n + 1, 0);
	v[2] = 1;
	for(int j =1; j < n; j++) {
		for (int i = 2 * j + 2; i >= 2; i--)
			v[i] = v[i] + v[i - 1] + v[i - 2];
	}
	for (int i = 2; i < v.size(); ++i)
		if (v[i] % 2 == 0)
			return i - 1;
	return -1;
}

int main() {
	int n;
	while (cin >> n)
		cout << ssss(n) << endl;
	system("pause");
	return 0;
}