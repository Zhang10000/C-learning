#include<vector>
#include<iostream>
using namespace std;
int main() {
	int n;
	while (cin >> n) {
		vector<int>num;
		vector<char>ema;
		char a;
		for (int i = 0; i < n; i++) {
			cin >> a;
			if (a == '+' || a == '-' || a == '*' || a == '/')
				ema.push_back(a);
			else 
				num.push_back(a - '0');
		}
		for (int i = 0; i < ema.size(); ++i) {
			switch (ema[i]){
			case '*':num[i] *= num[i + 1];
			case '/':num[i] /= num[i + 1];
			default:
				continue;
			}
		}
		for (int i = 0; i < ema.size(); ++i) {
			switch (ema[i]) {
			case '+':num[i] += num[i + 1];
			case '-':num[i] -= num[i + 1];
			default:
				continue;
			}
		}
		cout << num[0] << endl;
	}
	return 0;
}