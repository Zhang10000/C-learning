#include<iostream>
#include<vector>
using namespace std;
class Gift {
public:
	
	int find( vector<int>& v,int n) {
		for (int i = 0; i < v.size(); i += 2)
			if (v[i] == n)
				return i;
		return -1;
	}
	int getValue(vector<int> gifts, int n) {
		vector<int>v;
		for (int i = 0; i < gifts.size(); ++i) {
			if (find( v,gifts[i]) == -1) {
				v.push_back(gifts[i]);
				v.push_back(1);
			}
			else
				v[find(v,gifts[i]) + 1]++;
		}
		for (int i = 1; i < v.size(); i += 2)
			if (v[i] > n / 2)
				return v[i - 1];
		return 0;
	}
};
