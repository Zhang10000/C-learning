#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Mp3 {
public:
	Mp3(int n, string s) : _n(n),_s(s),_iter(1) {
		if (n > 4) {
			for (int i = 0; i < 4; ++i)
				_v.push_back(i + 1);
		}
		else 
			for (int i = 0; i < _n; ++i)
				_v.push_back(i + 1);
	}
	bool find() {
		for (int i = 0; i < _v.size(); ++i)
			if (_v[i] == _iter)
				return true;
		return false;
	}
	void Print() {
		for (int i = 0; i < _s.size(); ++i) {
			if (_s[i] == 'U') {
				_iter--;
				if (_iter < 1) {
					_iter = _n;
					for (int i = 0; i < _v.size(); ++i)
						_v[i] += (_n - _v.size());
				}
				else if (!find()) {
					for (int i = 0; i < _v.size(); ++i)
						_v[i]--;
				}
			}
			if (_s[i] == 'D') {
				_iter++;
				if (_iter > _n) {
					_iter = 1;
					for (int i = 0; i < _v.size(); ++i)
						_v[i] -= (_n - _v.size());
				}
				else if (!find()) {
					for (int i = 0; i < _v.size(); ++i)
						_v[i]++;
				}
			}
		}
		for (int i = 0; i < _v.size(); ++i)
			cout << _v[i] << ' ';
		cout << endl << _iter << endl;
	}	
private:
	vector<int>_v;
	int _iter;
	int _n;
	string _s;
};
int main() {
	int n;
	string s;
	while (cin >> n >> s) {
		Mp3 m = Mp3(n, s);
		m.Print();
	}
	system("pause");
	return 0;
}