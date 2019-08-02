#include<vector>
#include<set>
#include<iostream>
using namespace std;
int getFirstUnFormedNum(vector<int> arr, int len) {
	set<int> v;
	vector<int> tmp;
	int min = 0x7fffffff;
	for (int i = 0; i < len; ++i) {
		if (arr[i] < min) min = arr[i];
		for (set<int>::iterator x = v.begin(); x != v.end(); ++x) tmp.push_back(*x + arr[i]);
		for (unsigned int i = 0; i < tmp.size(); ++i) v.insert(tmp[i]);
		v.insert(arr[i]);
		tmp.clear();
	}
	for (int i = min; ; ++i) if (v.find(i) == v.end()) return i;
}