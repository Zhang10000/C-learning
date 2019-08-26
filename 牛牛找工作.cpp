#include<iostream>
#include<vector>
using namespace std;
int main() {
	int n, m;
	while (cin >> n >> m) {
		int a, b;
		vector<int>ability;
		vector<int>Salary;
		vector<int>Abi;
		for (int i = 0; i < n; i++) {
			cin >> a >> b;
			ability.push_back(a);
			Salary.push_back(b);
		}
		while (m) {
			cin >> a;
			Abi.push_back(a);
			m--;
		}
		while (n) {
			for (int i = 1; i < n; i++) {
				if (ability[i] < ability[i - 1]) {
					swap(ability[i], ability[i - 1]);
					swap(Salary[i], Salary[i - 1]);
				}
			}
			n--;
		}
		for (int i = 0; i < Abi.size(); i++) {
			int max = 0;
			for (int j = 0; j < ability.size(); j++) {
				if (Abi[i] >= ability[j])
					max = max > Salary[j] ? max : Salary[j];
				else
					break;
			}
			cout << max << endl;
		}
	}
	return 0;
}