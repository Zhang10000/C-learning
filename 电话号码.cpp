#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
vector<string>Control = { "","","ABC","DEF","GHI","JKL","MNO","PQRS","TUV","WXYZ" };
void tel(vector<string>&data) {
	vector<string>phone = { "","" };
	for (int i = 0; i < data.size(); ++i) {
		int j = 0;  string s;
		for (; j < data[i].size(); j++) {
			if (data[i][j] >= '0'&&data[i][j] <= '9') s.push_back(data[i][j]);
			else if(data[i][j] >= 'A' && data[i][j] <= 'Z'){
				for (int x = 2; x < 10; x++) if (Control[x].find(data[i][j]) != -1) s.push_back(x + '0');
			}
			if (s.size() == 7) break;
		}
		if (s.size() < 7) s += string(7 - s.size(), '0');
		int c = 0;
		if (find(phone.begin(), phone.end(), s) != phone.end()) {
			phone.erase(find(phone.begin(), phone.end(), s));
			for (int j = 0; j < phone.size(); ++j) {
				if (phone[j] > s)
					phone.insert(find(phone.begin(), phone.end(), phone[j]), s);
			}
			if (j == phone.size())
				phone.push_back(s);
		}
	}
	for (int i = 2; i < phone.size(); ++i) {
		for (int x = 0; x < phone[i].size(); ++x) x == 3 ? cout << '-' << phone[i][x] : cout << phone[i][x];
		cout << endl;
	}
}
int main() {
	int n;
	while (cin >> n) {
		vector<string>data;
		string a;
		while (n) {
			cin >> a;
			data.push_back(a);
			n--;
		}
		tel(data);
	}
	return 0;
}