#include <iostream>
using namespace std;
#define ll long long
ll gcd(ll a, ll b) {
	return b == 0 ? a : gcd(b, a%b);
}
int main(void) {
	int N;
	cin >> N;
	while (N--) {
		ll L, R, W, g;
		cin >> L >> R >> W;
		g = W < R ? gcd(R, W) : gcd(W, R);
		if (W + R - g > L) {
			puts("YES");
		}
		else {
			puts("NO");
		}
	}
	return 0;
}