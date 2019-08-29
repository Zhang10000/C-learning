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
// --------------------------------------------------------------------------------------------------------
class Solution {
public:
    int movingCount(int threshold, int rows, int cols)
    {
       bool *flag = new bool[rows * cols];
        for(int i = 0; i < rows * cols; i++)
            flag[i] = false;
        int count = moving(threshold, rows, cols, 0, 0, flag);
        return count; 
    }
     int moving(int threshold, int rows, int cols, int i, int j, bool* flag)
        {
        int count = 0;
        if(i >= 0 && i < rows && j >= 0 && j < cols && getsum(i) + getsum(j) <= threshold && flag[i * cols + j] == false)
            {
            flag[i * cols + j] = true;
            count =1 + moving(threshold, rows, cols, i + 1, j, flag)
                + moving(threshold, rows, cols, i - 1, j, flag)
                + moving(threshold, rows, cols, i , j - 1, flag)
                + moving(threshold, rows, cols, i, j + 1, flag);
        }
        return count;
    }
    int getsum(int num)
        {
        int sum = 0;
        while(num)
            {
            sum += num % 10;
            num /= 10;
              
        }
        return sum;
    }
};
