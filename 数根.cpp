#include<iostream>
#include<string>
using namespace std;
int main() {
	string n;
	while (cin >> n) {
		int cur = 0;
		for (auto& c : n) cur += c - '0';
		n = to_string(cur);
		while (n.size() > 1)
		{
			cur = 0;
			for (auto& c : n) cur += c - '0';
			n = to_string(cur);
		}
		cout << n << endl;
	}
	return 0;
}
