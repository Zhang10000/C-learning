#define LL long long
#include <iostream>
using namespace std;
int cnt = 1;
int k;
int A[100];
void solve(int n, int p) {
	if (n == 0 && p > k) {
		for (int i = 1; i < cnt; i++) {
			cout << A[i] << " ";
		}
		cout << endl;
	}
	if (n < 0 || p > k) return;
	else {
		for (int i = 1; i <= n; i++) {
			A[cnt++] = i;
			solve(n - i, p + 1);
			cnt--;
		}
	}
}
int main() {
	int n;
	while (cin >> n >> k) {
		solve(n, 1);
		cnt = 1;
	}
}