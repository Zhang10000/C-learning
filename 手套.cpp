#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Gloves {
public:
	int findMinimum(int n, vector<int> left, vector<int> right) {
		vector<int>s;
		int sum = 0;
		for (int i = 0; i < n; ++i) {
			if (left[i] * right[i] == 0) sum += (left[i] + right[i]);
			else s.push_back(left[i] > right[i] ? right[i] : left[i]);
		}
		sort(s.begin(), s.end());
		for (int i = s.size() - 1; i > 0; i--) sum += s[i];
		return sum + 2;
	}
};
