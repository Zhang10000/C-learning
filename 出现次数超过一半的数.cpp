#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
	int find(vector<int>s, int x) {
		for (int i = 0; i < s.size(); ++i)
			if (s[i] == x)
				return i;
		return -1;
	}
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		vector<int>v;
		vector<long>sum;
		for (int i = 0; i < numbers.size(); i++) {
			if (find(v, numbers[i]) != -1)
				sum[find(v, numbers[i])]++;
			else {
				v.push_back(numbers[i]); 
				sum.push_back(1);
			}	
		}
		int i = 0;
		for (; i < sum.size(); ++i) {
			double a = numbers.size() / 2;
			if ((double)sum[i] > a) {
				return v[i];
				break;
			}
		}
		if (i == sum.size())
			return 0;
	}
};