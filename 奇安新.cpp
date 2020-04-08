#include<iostream>
#include<string>
#include<assert.h>

using namespace std;


int main() {
	int a[16] = { 0,5,5,8,8,11,11,13,13,13,14,14,17,17,17,18 };
	int b;
	while (cin >> b) {
		if (b >= 15)
			cout << 18 << endl;
		else if (b < 0)
			cout << 0 << endl;
		else
			cout << a[b] << endl;
	}
	return 0;
}

int main1() {
	string s;
	while (getline(cin, s)) {
		int a[9] = { 0 };
		int i = 0;
		int sum = 0;
		for (auto e : s) {
			if (e == ',') {
				a[i] = sum;
				sum = 0;
				i++;
				continue;
			}
			sum = sum * 10 + e - '0';
		}
		a[8] = sum;
		if ((a[0] + a[1] + a[2] + a[3] == a[3] + a[4] + a[5] + a[6]) && (a[3] + a[4] + a[5] + a[6] == a[6] + a[7] + a[8] + a[0]))
			cout << "yes" << endl;
		else
			cout << "no" << endl;
	}
	return 0;
}
