#include<iostream>
#include<vector>
using namespace std;
bool Su(int a) {
	for (int i = 2; i * i <= a; ++i)
		if (a%i == 0)
			return false;
	return true;
}
vector<int>s;
void Fenjie(int a) {
	if (Su(a)) {
		s.push_back(a);
		return;
	}
	for (int i = 2;; i++)
		if (a%i == 0 && Su(i)) {
			s.push_back(i);
			Fenjie(a / i);
			return;
		}
}