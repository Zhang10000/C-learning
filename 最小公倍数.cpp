#include<iostream>
using namespace std;
int main78() {
	int a, b;
	cin >> a >> b;
	int i = a > b ? b : a;
	for (; i <= a * b; i++) {
		if (i%a == 0 && i%b == 0) {
			cout << i << endl;
			break;
		}
	}
	return 0;
}
