#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	int count;
	bool Istrue(int x, int y, int con,int threshold) {
		if (con > threshold)
			return false;
		if (x == 0 && y == 0)
			return true;
		else if (x == 0) {
			con += y % 10;
			Istrue(x, y / 10, con, threshold);
		}
		else if (y == 0) {
			con += x % 10;
			Istrue(x / 10, y, con, threshold);
		}
		else {
			con += x % 10;
			con += y % 10;
			Istrue(x / 10, y / 10, con, threshold);
		}
	}
	void Cango(int x, int y, int row, int col,int threshold) {
		if (x < row && x >= 0 && y < col && y >= 0 && Istrue(x, y, 0, threshold)) {
			count++;
			Cango(x + 1, y, row, col, threshold);
			Cango(x - 1, y, row, col, threshold);
			Cango(x, y + 1, row, col, threshold);
			Cango(x, y - 1, row, col, threshold);
		}
	}
	int movingCount(int threshold, int rows, int cols) {
		count = 1;
		Cango(0, 0, rows, cols,threshold);
		cout << count << endl;
		return count;
	}
};

int main() {
	int a, b, c;
	while (cin >> a >> b >> c) {
		Solution s;
		s.movingCount(c, a, b);
	}
}