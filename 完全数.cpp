#include<iostream>
using namespace std;

int Wqs(int&n) {
	int count = 0;
	for (int i = 3; i <= n; ++i) {
		int sum = 1;
		for (int j = 2; j < i; ++j)
			if (i%j == 0)
				sum += j;
		if (sum == i)
			count++;
	}
	if (count == 0)
		return -1;
	return count;
}

int main2() {
	int a;
	cin >> a;
	cout << Wqs(a) << endl;
	system("pause");
	return 0;
}