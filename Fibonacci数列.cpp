/*#include<iostream>
#include<vector>
using namespace std;
vector<long> v;

void Fibonacci(long s){
	v.push_back(0);
	v.push_back(1);
	for (long i = 2;; i++) {
		v.push_back(v[i - 1] + v[i - 2]);
		if (v[i] - s > 0)
			return;
	}
}

int main21() {
	long s;
	cin >> s;
	if (s < 0)
		return 0;
	Fibonacci(s);
	s = (v[v.size() - 1] - s) > (s - v[v.size() - 2]) ? (s - v[v.size() - 2]) : (v[v.size() - 1] - s);
	cout << s << endl;
	return 0;
}*/