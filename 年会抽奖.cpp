#include<vector>
#include<iostream>
using namespace std;
void Sss(long long n) {
	vector<long long>s = { 0, 0, 1 };
	vector<long long>v = { 0, 1, 2 };
	for (int i = 3; i < 21; ++i) {
		v.push_back(i*s[i - 1]);
		s.push_back((i - 1)*(s[i - 2] + s[i - 1]));
	}
	printf("%.2f%c\n", 1.0*s[n] / v[n] * 100, '%');
}