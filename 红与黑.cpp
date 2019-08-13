#include<iostream>
using namespace std;
int res, m, n;
int Ground[20][20] = { 0 };
void Black_tile(int x, int y) {
	if (Ground[x][y] == 1 || x < 0 || x >= m || y < 0 || y >= n)
		return;
	res++;
	Ground[x][y] = 1;
	Black_tile(x + 1, y);
	Black_tile(x - 1, y);
	Black_tile(x, y + 1);
	Black_tile(x, y - 1);
}
int main() {
	int m, n;
	while (cin >> m >> n) {
		int x, y;
		for (int i = 0; i < m; ++i) {
			char a;
			for (int j = 0; j < n; ++j) {
				cin >> a;
				if (a == '#')
					Ground[i][j] = 1;
				if (a == '@') {
					x = i;
					y = j;
				}
			}
		}
		Black_tile(x, y);
		cout << res << endl;
		res = 0;
		memset(Ground, 0, sizeof(Ground));
	}
	return 0;
}