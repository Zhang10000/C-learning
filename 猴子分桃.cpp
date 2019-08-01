#include<iostream>
#include<cmath>
using namespace std;
void Tao(int & n) { cout << (long)pow(5, n) - 4 << " " << pow(4, n) + n - 4 << endl; }
int main() {
	int a;
	while (cin >> a) {
		if (a == 0) break;
		Tao(a);
	}
	return 0;
}