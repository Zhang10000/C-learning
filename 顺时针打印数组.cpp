#include<vector>
#include<iostream>
using namespace std;
class Printer {
public:
	vector<int> clockwisePrint(vector<vector<int>> mat, int n, int m) {
		int ns = 0, ms = 0;
		vector<int>s;
		clock(s, mat, ns, ms, n - 1, m - 1);
		return s;
	}
	void clock(vector<int>&s, vector<vector<int>>& mat, int ns, int ms, int n, int m) {
		if (ms > m || ns > n)
			return;
		if (ms == m && ns == n) {
			s.push_back(mat[n][m]);
			return;
		}
		else if (ms == m) {
			for (int i = ns; i <= n; i++)
				s.push_back(mat[i][m]);
			return;
		}
		else if (ns == n) {
			for (int j = ms; j <= m; j++)
				s.push_back(mat[n][j]);
			return;
		}
		else {
			for (int i = ns, j = ms; j <= m; j++)
				s.push_back(mat[i][j]);
			for (int i = ns + 1, j = m; i <= n; i++)
				s.push_back(mat[i][j]);
			for (int i = n, j = m - 1; j >= ms; j--)
				s.push_back(mat[i][j]);
			for (int i = n - 1, j = ms; i > ns; i--)
				s.push_back(mat[i][j]);
			clock(s, mat, ns + 1, ms + 1, n - 1, m - 1);
		}
	}
};
int main() {
	Printer p;
	vector < vector<int >>ss = { { 1, 2, 3 } ,{ 4, 5, 6 } ,{ 7, 8, 9 } };
	p.clockwisePrint(ss, 3, 3);
}