#include<iostream>
#include<vector>
using namespace std;
bool is24(const vector<double> v, int num, double sum){
	if (v.empty())
		return sum == num;
	for (size_t i = 0; i < v.size(); i++)
	{
		vector<double> tmp(v);
		tmp.erase(tmp.begin() + i);
		if (is24(tmp, num, sum + v[i])
			|| is24(tmp, num, sum - v[i])
			|| is24(tmp, num, sum * v[i])
			|| is24(tmp, num, sum / v[i]))
			return true;
	}
	return false;
}
int main(){
	vector<double> v(4);
	while (cin >> v[0] >> v[1] >> v[2] >> v[3])
		cout << (is24(v, 24, 0) ? "true" : "false") << endl;
	return 0;
}