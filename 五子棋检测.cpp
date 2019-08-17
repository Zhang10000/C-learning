#include<iostream>
using namespace std;
bool is_Win(char check[20][20]) {
	for (int i = 0; i < 20; ++i) {
		for (int j = 0; j < 16; ++j) {
			if (check[i][j] == check[i][j + 1]
				&& check[i][j + 1] == check[i][j + 2]
				&& check[i][j + 2] == check[i][j + 3]
				&& check[i][j + 3] == check[i][j + 4]) {
				cout << "YES" << endl;
				return true;
			}
		}
	}
	for (int i = 0; i < 16; ++i) {
		for (int j = 0; j < 20; ++j) {
			if (check[i][j] == check[i + 1][j]
				&& check[i + 1][j] == check[i + 2][j]
				&& check[i + 2][j] == check[i + 3][j]
				&& check[i + 3][j] == check[i + 4][j]) {
				cout << "Yes" << endl;
				return true;
			}

		}
	}
	for (int i = 0; i < 16; ++i) {
		for (int j = 0; j < 16; ++j) {
			if (check[i][j] == check[i + 1][j + 1]
				&& check[i + 1][j + 1] == check[i + 2][j + 2]
				&& check[i + 2][j + 2] == check[i + 3][j + 3]
				&& check[i + 3][j + 3] == check[i + 4][j + 4]) {
				cout << "Yes" << endl;
				return true;
			}
		}
	}
	for (int i = 19; i > 3; --i) {
		for (int j = 0; j < 16; --j) {
			if (check[i][j] == check[i - 1][j + 1]
				&& check[i - 1][j + 1] == check[i - 2][j + 2]
				&& check[i - 2][j + 2] == check[i - 3][j + 3]
				&& check[i - 3][j + 3] == check[i - 4][j + 4]) {
				cout << "Yes" << endl;
				return true;
			}
		}
	}
	return false;
}
int main() {
	char check[20][20] = { '.' };
	char as;
	while (1) {
		for (int i = 0; i < 20; ++i) {
			for (int j = 0; j < 20; ++j) {
				cin >> as;
				if (as != '.')
					check[i][j] = as;
			}
		}
		if (!is_Win(check))
			cout << "No" << endl;
	}
	return 0;
}